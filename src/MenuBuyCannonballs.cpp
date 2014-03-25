#include "MenuBuyCannonballs.h"

MenuBuyCannonballs::MenuBuyCannonballs()
:Menu(sf::Sprite()),
ShipHandler(),
m_netWooden(0),
m_netStone(0),
m_netCobbleStone(0),
m_netMetal(0),
m_golds(0),
m_ID(0),
m_ammo(0)
{
    m_menuWoodenCannonballs.setFont(FONT_PIECES_OF_EIGHT);
    m_menuWoodenCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuWoodenCannonballs.setLabelNameText(WOODEN_CANNONBALLS_TYPE);
    m_menuWoodenCannonballs.setLabelImageTexture(CANNONBALLS_WOOD);
    m_menuWoodenCannonballs.setButtonTexture(BUTTON_BUY);
    m_menuWoodenCannonballs.setButtonTextureFocused(BUTTON_BUY_FOCUS);
    m_menuWoodenCannonballs.setTextfieldTexture(TEXTFIELD_1);
    m_menuWoodenCannonballs.setTextfieldTextureFocused(TEXTFIELD_1_FOCUS);
    m_menuWoodenCannonballs.setPosition(350, 100);

    m_menuStoneCannonballs.setFont(FONT_PIECES_OF_EIGHT);
    m_menuStoneCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuStoneCannonballs.setLabelNameText(STONE_CANNONBALLS_TYPE);
    m_menuStoneCannonballs.setLabelImageTexture(CANNONBALLS_STONE);
    m_menuStoneCannonballs.setButtonTexture(BUTTON_BUY);
    m_menuStoneCannonballs.setButtonTextureFocused(BUTTON_BUY_FOCUS);
    m_menuStoneCannonballs.setTextfieldTexture(TEXTFIELD_1);
    m_menuStoneCannonballs.setTextfieldTextureFocused(TEXTFIELD_1_FOCUS);
    m_menuStoneCannonballs.setPosition(800, 100);

    m_menuCobbleStoneCannonballs.setFont(FONT_PIECES_OF_EIGHT);
    m_menuCobbleStoneCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuCobbleStoneCannonballs.setLabelNameText(COBBLESTONE_CANNONBALLS_TYPE);
    m_menuCobbleStoneCannonballs.setLabelImageTexture(CANNONBALLS_COBBLESTONE);
    m_menuCobbleStoneCannonballs.setButtonTexture(BUTTON_BUY);
    m_menuCobbleStoneCannonballs.setButtonTextureFocused(BUTTON_BUY_FOCUS);
    m_menuCobbleStoneCannonballs.setTextfieldTexture(TEXTFIELD_1);
    m_menuCobbleStoneCannonballs.setTextfieldTextureFocused(TEXTFIELD_1_FOCUS);
    m_menuCobbleStoneCannonballs.setPosition(350, 400);

    m_menuMetalCannonballs.setFont(FONT_PIECES_OF_EIGHT);
    m_menuMetalCannonballs.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_menuMetalCannonballs.setLabelNameText(METAL_CANNONBALLS_TYPE);
    m_menuMetalCannonballs.setLabelImageTexture(CANNONBALLS_METAL);
    m_menuMetalCannonballs.setButtonTexture(BUTTON_BUY);
    m_menuMetalCannonballs.setButtonTextureFocused(BUTTON_BUY_FOCUS);
    m_menuMetalCannonballs.setTextfieldTexture(TEXTFIELD_1);
    m_menuMetalCannonballs.setTextfieldTextureFocused(TEXTFIELD_1_FOCUS);
    m_menuMetalCannonballs.setPosition(800, 400);
}

void MenuBuyCannonballs::update(sf::Event const &event)
{
    m_menuWoodenCannonballs.update(event);
    m_menuStoneCannonballs.update(event);
    m_menuCobbleStoneCannonballs.update(event);
    m_menuMetalCannonballs.update(event);

    if (m_menuWoodenCannonballs.getValue() != 0)
    {
        // BUY WOODEN CANNONBALLS
        if (m_netWooden == 0)
        {
            m_netWooden = this->request(0, BUY_WOODEN_CANNONBALLS, m_menuWoodenCannonballs.getValue(), 0, 0, 0);
        }
        else if (m_netWooden == 1)
        {
             m_netWooden = this->request(1, BUY_WOODEN_CANNONBALLS, m_menuWoodenCannonballs.getValue(), 0, 0, 0);
        }
        else if (m_netWooden == 2)
        {
            *m_packet >> m_ammo >> m_golds;

            Cannonballs b;
            b.setType(WOODEN_CANNONBALLS_TYPE);
            b.setAmmo(m_ammo);

            m_ship->addCannonballs(b);
            m_ship->setGolds(m_golds);

            //std::cout << "Ammo: " << m_ammo << " Golds: " << m_ship->getGolds() << std::endl;

            m_menuWoodenCannonballs.resetValue();
            m_packet->clear();
            m_netWooden = 0;
        }

    }
    else if (m_menuCobbleStoneCannonballs.getValue() != 0)
    {
        // BUY STONE CANNONBALLS

        if (m_netCobbleStone == 0)
        {
            m_netCobbleStone = this->request(0, BUY_COBBLESTONE_CANNONBALLS, m_menuCobbleStoneCannonballs.getValue());
        }
        else if (m_netCobbleStone == 1)
        {
            m_netCobbleStone = this->request(1, BUY_COBBLESTONE_CANNONBALLS, m_menuCobbleStoneCannonballs.getValue());

        }
        else if (m_netCobbleStone == 2)
        {
            *m_packet >> m_ammo >> m_golds;

            Cannonballs b;
            b.setType(COBBLESTONE_CANNONBALLS_TYPE);
            b.setAmmo(m_ammo);

            m_ship->addCannonballs(b);
            m_ship->setGolds(m_golds);

            //std::cout << " Ammo: " << m_ammo << " Golds: " << m_ship->getGolds() << std::endl;

            m_menuCobbleStoneCannonballs.resetValue();
            m_packet->clear();
            m_netCobbleStone = 0;
        }
    }
    else if (m_menuMetalCannonballs.getValue() != 0)
    {
        // BUY STONE CANNONBALLS
        if (m_netMetal == 0)
        {
            m_netMetal = this->request(0, BUY_METAL_CANNONBALLS, m_menuMetalCannonballs.getValue());
        }
        else if (m_netMetal == 1)
        {
            m_netMetal = this->request(1, BUY_METAL_CANNONBALLS, m_menuMetalCannonballs.getValue());
        }
        else if (m_netMetal == 2)
        {
            *m_packet >> m_ammo >> m_golds;

            Cannonballs b;
            b.setType(METAL_CANNONBALLS_TYPE);
            b.setAmmo(m_ammo);

            m_ship->addCannonballs(b);
            m_ship->setGolds(m_golds);

            //std::cout << " Ammo: " << m_ammo << " Golds: " << m_ship->getGolds() << std::endl;

            m_menuMetalCannonballs.resetValue();
            m_packet->clear();
            m_netMetal = 0;
        }
    }
    else if (m_menuStoneCannonballs.getValue() != 0)
    {
        // BUY STONE CANNONBALLS
        if (m_netStone == 0)
        {
            m_netStone = this->request(0, BUY_STONE_CANNONBALLS, m_menuStoneCannonballs.getValue());
        }
        else if (m_netStone == 1)
        {
            m_netStone = this->request(1, BUY_STONE_CANNONBALLS, m_menuStoneCannonballs.getValue());
        }
        else if (m_netStone == 2)
        {
            *m_packet >> m_ammo >> m_golds;

            Cannonballs b;
            b.setType(STONE_CANNONBALLS_TYPE);
            b.setAmmo(m_ammo);

            m_ship->addCannonballs(b);
            m_ship->setGolds(m_golds);

            //std::cout << " Ammo: " << m_ammo << " Golds: " << m_ship->getGolds() << std::endl;

            m_menuStoneCannonballs.resetValue();
            m_packet->clear();
            m_netStone = 0;
        }
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
