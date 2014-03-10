#include "MenuBuyCannonballs.h"

MenuBuyCannonballs::MenuBuyCannonballs()
:Menu(sf::Sprite())
{
    m_menuWoodenCannonballs.setFont(POLICE_PIECES_OF_EIGHT);
    m_menuWoodenCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuWoodenCannonballs.setLabelNameText("Wooden Ammo");
    m_menuWoodenCannonballs.setLabelImageTexture(MENU_BUYCANNONBALLS_WOODEN_CANNONBALLS);
    m_menuWoodenCannonballs.setButtonTexture(MENU_BUTTON_BUY);
    m_menuWoodenCannonballs.setButtonTextureFocused(MENU_BUTTON_BUYFOCUS);
    m_menuWoodenCannonballs.setTextfieldTexture(MENU_TEXTFIELD1);
    m_menuWoodenCannonballs.setTextfieldTextureFocused(MENU_TEXTFIELDFOCUS1);
    m_menuWoodenCannonballs.setPosition(350, 100);

    m_menuStoneCannonballs.setFont(POLICE_PIECES_OF_EIGHT);
    m_menuStoneCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuStoneCannonballs.setLabelNameText("Stone Ammo");
    m_menuStoneCannonballs.setLabelImageTexture(MENU_BUYCANNONBALLS_STONE_CANNONBALLS);
    m_menuStoneCannonballs.setButtonTexture(MENU_BUTTON_BUY);
    m_menuStoneCannonballs.setButtonTextureFocused(MENU_BUTTON_BUYFOCUS);
    m_menuStoneCannonballs.setTextfieldTexture(MENU_TEXTFIELD1);
    m_menuStoneCannonballs.setTextfieldTextureFocused(MENU_TEXTFIELDFOCUS1);
    m_menuStoneCannonballs.setPosition(800, 100);

    m_menuCobbleStoneCannonballs.setFont(POLICE_PIECES_OF_EIGHT);
    m_menuCobbleStoneCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuCobbleStoneCannonballs.setLabelNameText("CobbleStone Ammo");
    m_menuCobbleStoneCannonballs.setLabelImageTexture(MENU_BUYCANNONBALLS_COBBLESTONE_CANNONBALLS);
    m_menuCobbleStoneCannonballs.setButtonTexture(MENU_BUTTON_BUY);
    m_menuCobbleStoneCannonballs.setButtonTextureFocused(MENU_BUTTON_BUYFOCUS);
    m_menuCobbleStoneCannonballs.setTextfieldTexture(MENU_TEXTFIELD1);
    m_menuCobbleStoneCannonballs.setTextfieldTextureFocused(MENU_TEXTFIELDFOCUS1);
    m_menuCobbleStoneCannonballs.setPosition(350, 400);

    m_menuMetalCannonballs.setFont(POLICE_PIECES_OF_EIGHT);
    m_menuMetalCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuMetalCannonballs.setLabelNameText("Metal Ammo");
    m_menuMetalCannonballs.setLabelImageTexture(MENU_BUYCANNONBALLS_METAL_CANNONBALLS);
    m_menuMetalCannonballs.setButtonTexture(MENU_BUTTON_BUY);
    m_menuMetalCannonballs.setButtonTextureFocused(MENU_BUTTON_BUYFOCUS);
    m_menuMetalCannonballs.setTextfieldTexture(MENU_TEXTFIELD1);
    m_menuMetalCannonballs.setTextfieldTextureFocused(MENU_TEXTFIELDFOCUS1);
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
