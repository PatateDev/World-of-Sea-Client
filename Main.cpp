#include "Main.h"
#include "Class.h"
#include <sstream>

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

    Ship myShip;
    MenuBar menuBar;
    MenuBuyCannonballs menuBuyCannonballs;
    MenuBuyCannons menuBuyCannons;
    MenuEquipCannonballs menuEquipCannonballs;
    MenuEquipCannons menuEquipCannons;
    
    sf::String username, session;

    // INITIALISATION
    myShip.setGolds(1000000);
    myShip.setMaxCannon(100);

    menuBar.setShip(myShip);
    menuBuyCannonballs.setShip(myShip);
    menuBuyCannons.setShip(myShip);
    menuEquipCannonballs.setShip(myShip);
    menuEquipCannons.setShip(myShip);
    
    if (argc >= 3)
    {
        username = argv[1];
        session = argv[2];
        std::cout << "Launching, with player : " << argv[1] << " and session : " << argv[2] << std::endl;
    }
    else
        std::cout << "Launching client in offline mode" << std::endl;

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
