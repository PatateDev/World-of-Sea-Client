#include "Main.h"
#include "Class.h"
#include <sstream>

bool connect(sf::TcpSocket &sock, sf::String username, sf::String session);
bool getShip(sf::TcpSocket &sock, Ship &ship);

int main(int argc, char*argv[])
{
    std::ostringstream title;
    title << "World of Sea v.";
    title << CLIENT_VERSION_MAJOR << ".";
    title << CLIENT_VERSION_MINOR << ".";
    title << CLIENT_VERSION_PATCH;

    // DECLARATION
    sf::RenderWindow window(sf::VideoMode(LAUNCHER_WIDTH_X, LAUNCHER_HEIGHT_Y), title.str(), sf::Style::Close | sf::Style::Titlebar);
    sf::Event event;

    sf::TcpSocket socket;

    Ship myShip;
    MenuBar menuBar;
    MenuBuyCannonballs menuBuyCannonballs;
    MenuBuyCannons menuBuyCannons;
    MenuEquipCannonballs menuEquipCannonballs;
    MenuEquipCannons menuEquipCannons;

    NetworkReceive networkReceive;

    sf::String username, session;

    // INITIALISATION
    myShip.setGolds(1000000);
    myShip.setMaxCannon(100);

    menuBar.setShip(myShip);
    menuBuyCannonballs.setShip(myShip);
    menuBuyCannons.setShip(myShip);
    menuEquipCannonballs.setShip(myShip);
    menuEquipCannons.setShip(myShip);

    menuBuyCannonballs.setNetworkReceive(networkReceive);
    menuBuyCannons.setNetworkReceive(networkReceive);
    menuEquipCannonballs.setNetworkReceive(networkReceive);
    menuEquipCannons.setNetworkReceive(networkReceive);

    menuBuyCannonballs.setSocket(socket);
    menuBuyCannons.setSocket(socket);
    menuEquipCannonballs.setSocket(socket);
    menuEquipCannons.setSocket(socket);

    if (argc >= 3)
    {
        username = argv[1];
        session = argv[2];
        std::cout << "Launching, with player : " << argv[1] << " and session : " << argv[2] << std::endl;

    }
    else
    {
        std::cout << "Launching client in offline mode" << std::endl;
        username = "obitonio";
        session = "NULL";
        if (!connect(socket, username, session)) //TODO Moove connect function
            return EXIT_FAILURE;

        getShip(socket, myShip);
    }

    sf::Packet test;
    test << "stop";

    socket.send(test);

    while (window.isOpen())
    {
        window.waitEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();

        menuBar.update(event);

        window.clear(sf::Color::White);
        menuBar.render(window);

        switch (menuBar.getMenu())
        {
        case 0:
            break;
        case 1:
            menuBuyCannonballs.update(event);
            menuBuyCannonballs.render(window);
            break;
        case 2:
            menuBuyCannons.update(event);
            menuBuyCannons.render(window);
            break;
        case 4:
            menuEquipCannonballs.update(event);
            menuEquipCannonballs.render(window);
            break;
        case 5:
            menuEquipCannons.update(event);
            menuEquipCannons.render(window);
            break;
        case 7:
            window.close();
            break;
        }

        window.display();
    }


    return 0;
}

bool connect (sf::TcpSocket &sock, sf::String username, sf::String session)
{
    sf::Socket::Status status;
    int response;

    std::cout << "NETWORK: Connect to the server..." << std::endl;

    status = sock.connect(NETWORK_IP, NETWORK_PORT);
    if (status == sf::Socket::Done)
    {
        sf::Packet packet;
        packet << CONNECT << username << session; //TODO Need session
        sock.send(packet);

        sock.receive(packet);
        packet >> response;

        sock.setBlocking(false);

        std::cout << response << std::endl;

        if (OK == response)
        {
            std::cout << "NETWORK: Connected on Server" << std::endl;
            return true;
        }
        else
        {
            std::cout << "NETWORK: Can't connect: " << response << std::endl;
            return false;
        }

    }
    else
    {
        std::cout << "ERROR: CAN'T CONNECT TO THE SERVER" << std::endl;
        return false;
    }
}

bool getShip(sf::TcpSocket &sock, Ship &ship)
{
    int value;
    sf::Packet packet;
    Cannonballs ammo;

    sock.setBlocking(true);

    // WOODEN CANNONBALLS
    packet.clear();
    packet << WOODEN_CANNONBALLS;
    sock.send(packet);

    packet.clear();
    sock.receive(packet);
    packet >> value;

    ammo.setType(WOODEN_CANNONBALLS_TYPE);
    ammo.setAmmo(value);
    ship.addCannonballs(ammo);

    // STONE CANNONBALLS
    packet.clear();
    packet << STONE_CANNONBALLS;
    sock.send(packet);

    packet.clear();
    sock.receive(packet);
    packet >> value;

    ammo.setType(STONE_CANNONBALLS_TYPE);
    ammo.setAmmo(value);
    ship.addCannonballs(ammo);

    // COBBLESTONE CANNONBALLS
    packet.clear();
    packet << COBBLESTONE_CANNONBALLS;
    sock.send(packet);

    packet.clear();
    sock.receive(packet);
    packet >> value;

    ammo.setType(COBBLESTONE_CANNONBALLS_TYPE);
    ammo.setAmmo(value);
    ship.addCannonballs(ammo);

     // METAL CANNONBALLS
    packet.clear();
    packet << METAL_CANNONBALLS;
    sock.send(packet);

    packet.clear();
    sock.receive(packet);
    packet >> value;

    ammo.setType(METAL_CANNONBALLS_TYPE);
    ammo.setAmmo(value);
    ship.addCannonballs(ammo);



    sock.setBlocking(false);
}
