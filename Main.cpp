#include "Main.h"
#include "Class.h"

int main(int argc, char*argv[])
{
    // DECLARATION
    sf::RenderWindow window(sf::VideoMode(LAUNCHER_WIDTH_X, LAUNCHER_HEIGHT_Y), "World of Sea v0", sf::Style::Close | sf::Style::Titlebar);
    sf::Event event;
    MenuBar menuBar;
    MenuBuyCannonballs menuBuyCannonballs;
    MenuTrade menuTrade;
    Ship myShip;

    /*menuTrade.setFont("resources/fonts/arial.ttf");
    menuTrade.setLabelDescriptionText("Description");
    menuTrade.setLabelNameText("Wooden Ammo");
    menuTrade.setLabelTextfieldText("Textfield");
    menuTrade.setLabelImageTexture("resources/sprites/Boulet bois.jpg");

    menuTrade.setButtonTexture("resources/sprites/Bouton buy cannonballs.png");
    menuTrade.setButtonTextureFocused("resources/sprites/Bouton buy cannonballs focus.png");

    menuTrade.setTextfieldTexture("resources/sprites/textfield.png");
    menuTrade.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");

    menuTrade.setPosition(200, 200);*/



    while (window.isOpen())
    {
        window.waitEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();

        menuBar.update(event);

        window.clear(sf::Color::White);

        menuBar.render(window);
        //menuTrade.update(event);
        //menuTrade.render(window);
        switch (menuBar.getMenu())
        {
        case 0:
            break;
        case 1:
            menuBuyCannonballs.update(event);
            menuBuyCannonballs.render(window);
            break;
        case 2:
            break;
        case 7:
            window.close();
            break;
        }

        window.display();
    }


    return 0;
}
