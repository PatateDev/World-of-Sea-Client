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
    m_menuWoodenCannonballs.setPosition(350, 100);

    m_menuStoneCannonballs.setFont("resources/fonts/Pieces of Eight.ttf");
    m_menuStoneCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuStoneCannonballs.setLabelNameText("Stone Ammo");
    m_menuStoneCannonballs.setLabelImageTexture("resources/sprites/Boulet pierre2.jpg");
    m_menuStoneCannonballs.setButtonTexture("resources/sprites/Bouton Buy2.png");
    m_menuStoneCannonballs.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    m_menuStoneCannonballs.setTextfieldTexture("resources/sprites/textfield.png");
    m_menuStoneCannonballs.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
    m_menuStoneCannonballs.setPosition(800, 100);

    m_menuCobbleStoneCannonballs.setFont("resources/fonts/Pieces of Eight.ttf");
    m_menuCobbleStoneCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuCobbleStoneCannonballs.setLabelNameText("CobbleStone Ammo");
    m_menuCobbleStoneCannonballs.setLabelImageTexture("resources/sprites/Boulet beton2.png");
    m_menuCobbleStoneCannonballs.setButtonTexture("resources/sprites/Bouton Buy2.png");
    m_menuCobbleStoneCannonballs.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    m_menuCobbleStoneCannonballs.setTextfieldTexture("resources/sprites/textfield.png");
    m_menuCobbleStoneCannonballs.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
    m_menuCobbleStoneCannonballs.setPosition(350, 400);

    m_menuMetalCannonballs.setFont("resources/fonts/Pieces of Eight.ttf");
    m_menuMetalCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuMetalCannonballs.setLabelNameText("CobbleStone Ammo");
    m_menuMetalCannonballs.setLabelImageTexture("resources/sprites/Boulet metal2.png");
    m_menuMetalCannonballs.setButtonTexture("resources/sprites/Bouton Buy2.png");
    m_menuMetalCannonballs.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    m_menuMetalCannonballs.setTextfieldTexture("resources/sprites/textfield.png");
    m_menuMetalCannonballs.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
    m_menuMetalCannonballs.setPosition(800, 400);
}

void MenuBuyCannonballs::update(sf::Event const &event)
{
    m_menuWoodenCannonballs.update(event);
    m_menuStoneCannonballs.update(event);
    m_menuCobbleStoneCannonballs.update(event);
    m_menuMetalCannonballs.update(event);

    if ((m_menuWoodenCannonballs.getValue() != 0) && ((m_ship->getGolds() - (WOODEN_CANNONBALLS_PRICE * m_menuWoodenCannonballs.getValue())) > 0))
    {
        // BUY WOODEN CANNONBALLS
        m_ship->setGolds(m_ship->getGolds() - (WOODEN_CANNONBALLS_PRICE * m_menuWoodenCannonballs.getValue()));
        Cannonballs b;
        b.setType("Wooden Ammo");
        b.setAmmo(m_menuWoodenCannonballs.getValue());
        m_ship->addCannonballs(b);
        m_menuWoodenCannonballs.resetValue();
    }
    else if ((m_menuCobbleStoneCannonballs.getValue() != 0) && ((m_ship->getGolds() - (COBBLESTONE_CANNONBALLS_PRICE * m_menuCobbleStoneCannonballs.getValue())) > 0))
    {
        // BUY STONE CANNONBALLS
        m_ship->setGolds(m_ship->getGolds() - (COBBLESTONE_CANNONBALLS_PRICE * m_menuCobbleStoneCannonballs.getValue()));
        Cannonballs b;
        b.setType("Cobblestone Ammo");
        b.setAmmo(m_menuCobbleStoneCannonballs.getValue());
        m_ship->addCannonballs(b);
        m_menuCobbleStoneCannonballs.resetValue();
    }
    else if ((m_menuMetalCannonballs.getValue() != 0) && ((m_ship->getGolds() - (METAL_CANNONBALLS_PRICE * m_menuMetalCannonballs.getValue())) > 0))
    {
        // BUY STONE CANNONBALLS
        m_ship->setGolds(m_ship->getGolds() - (METAL_CANNONBALLS_PRICE * m_menuMetalCannonballs.getValue()));
        Cannonballs b;
        b.setType("Metal Ammo");
        b.setAmmo(m_menuMetalCannonballs.getValue());
        m_ship->addCannonballs(b);
        m_menuMetalCannonballs.resetValue();
    }
    else if ((m_menuStoneCannonballs.getValue() != 0) && ((m_ship->getGolds() - (STONE_CANNONBALLS_PRICE * m_menuStoneCannonballs.getValue())) > 0))
    {
        // BUY STONE CANNONBALLS
        m_ship->setGolds(m_ship->getGolds() - (STONE_CANNONBALLS_PRICE * m_menuStoneCannonballs.getValue()));
        Cannonballs b;
        b.setType("Stone Ammo");
        b.setAmmo(m_menuStoneCannonballs.getValue());
        m_ship->addCannonballs(b);
        m_menuStoneCannonballs.resetValue();
    }
}

void MenuBuyCannonballs::onComponentEvent(const sf::ui::ComponentEvent &event)
{

}

void MenuBuyCannonballs::render(sf::RenderTarget &target)
{
    m_menuWoodenCannonballs.render(target);
    m_menuStoneCannonballs.render(target);
    m_menuCobbleStoneCannonballs.render(target);
    m_menuMetalCannonballs.render(target);
}

MenuBuyCannonballs::~MenuBuyCannonballs()
{
    //dtor
}
