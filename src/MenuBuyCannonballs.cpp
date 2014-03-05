#include "MenuBuyCannonballs.h"

MenuBuyCannonballs::MenuBuyCannonballs()
:Menu(sf::Sprite())
{
    menuTrade.setFont("resources/fonts/arial.ttf");

    menuTrade.setLabelDescriptionText("Description\nDamage\nWeight");
    menuTrade.setLabelNameText("Wooden Ammo");
    menuTrade.setLabelTextfieldText("Textfield");
    menuTrade.setLabelImageTexture("resources/sprites/Boulet bois2.png");

    menuTrade.setButtonTexture("resources/sprites/Bouton Buy2.png");
    menuTrade.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");

    menuTrade.setTextfieldTexture("resources/sprites/textfield.png");
    menuTrade.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");

    menuTrade.setBackgroundTexture("resources/sprites/Background trade.png");

    menuTrade.setPosition(400, 200);
}

void MenuBuyCannonballs::update(sf::Event const &event)
{
    menuTrade.update(event);
}

void MenuBuyCannonballs::onComponentEvent(const sf::ui::ComponentEvent &event)
{

}

void MenuBuyCannonballs::render(sf::RenderTarget &target)
{
    menuTrade.render(target);
}

MenuBuyCannonballs::~MenuBuyCannonballs()
{
    //dtor
}
