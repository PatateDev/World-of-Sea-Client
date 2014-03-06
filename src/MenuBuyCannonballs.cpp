#include "MenuBuyCannonballs.h"

MenuBuyCannonballs::MenuBuyCannonballs()
:Menu(sf::Sprite())
{
    m_menuWoodenCannonballs.setFont("resources/fonts/Pieces of Eight.ttf");
    m_menuWoodenCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuWoodenCannonballs.setLabelNameText("Wooden Ammo");
    m_menuWoodenCannonballs.setLabelImageTexture("resources/sprites/Boulet bois3.png");
    m_menuWoodenCannonballs.setButtonTexture("resources/sprites/Bouton Buy2.png");
    m_menuWoodenCannonballs.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    m_menuWoodenCannonballs.setTextfieldTexture("resources/sprites/textfield.png");
    m_menuWoodenCannonballs.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
    m_menuWoodenCannonballs.setPosition(350, 0);

    m_menuStoneCannonballs.setFont("resources/fonts/Pieces of Eight.ttf");
    m_menuStoneCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuStoneCannonballs.setLabelNameText("Stone Ammo");
    m_menuStoneCannonballs.setLabelImageTexture("resources/sprites/Boulet pierre2.jpg");
    m_menuStoneCannonballs.setButtonTexture("resources/sprites/Bouton Buy2.png");
    m_menuStoneCannonballs.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    m_menuStoneCannonballs.setTextfieldTexture("resources/sprites/textfield.png");
    m_menuStoneCannonballs.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
    m_menuStoneCannonballs.setPosition(800, 0);

}

void MenuBuyCannonballs::update(sf::Event const &event)
{
    m_menuWoodenCannonballs.update(event);
    m_menuStoneCannonballs.update(event);

    if (m_menuWoodenCannonballs.getValue() != 0)
    {
        Cannonballs b;
        b.setType("Wooden Ammo");
        b.setAmmo(m_menuWoodenCannonballs.getValue());
        m_ship->addCannonballs(b);
        m_menuWoodenCannonballs.resetValue();
    }
}

void MenuBuyCannonballs::onComponentEvent(const sf::ui::ComponentEvent &event)
{

}

void MenuBuyCannonballs::render(sf::RenderTarget &target)
{
    m_menuWoodenCannonballs.render(target);
    m_menuStoneCannonballs.render(target);
}

MenuBuyCannonballs::~MenuBuyCannonballs()
{
    //dtor
}
