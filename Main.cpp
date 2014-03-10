#include "Main.h"
#include "Class.h"

int main(int argc, char*argv[])
{
    // DECLARATION
    sf::RenderWindow window(sf::VideoMode(LAUNCHER_WIDTH_X, LAUNCHER_HEIGHT_Y), "World of Sea v0", sf::Style::Close | sf::Style::Titlebar);
    sf::Event event;

    Ship myShip;
    MenuBar menuBar;
    MenuBuyCannonballs menuBuyCannonballs;
    MenuBuyCannons menuBuyCannons;
    MenuEquipCannonballs menuEquipCannonballs;
    MenuEquipCannons menuEquipCannons;

    // INITIALISATION
    myShip.setGolds(1000000);
    myShip.setMaxCannon(100);

    menuBar.setShip(myShip);
    menuBuyCannonballs.setShip(myShip);
    menuBuyCannons.setShip(myShip);
    menuEquipCannonballs.setShip(myShip);
    menuEquipCannons.setShip(myShip);

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
