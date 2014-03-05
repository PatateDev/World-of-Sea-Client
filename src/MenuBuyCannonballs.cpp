#include "MenuBuyCannonballs.h"

MenuBuyCannonballs::MenuBuyCannonballs()
:Menu(sf::Sprite())
{
    menuTrade.setFont("resources/fonts/Pieces of Eight.ttf");
    menuTrade.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    menuTrade.setLabelNameText("Wooden Ammo");
    menuTrade.setLabelImageTexture("resources/sprites/Boulet bois3.png");
    menuTrade.setButtonTexture("resources/sprites/Bouton Buy2.png");
    menuTrade.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    menuTrade.setTextfieldTexture("resources/sprites/textfield.png");
    menuTrade.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
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
