#include "MenuEquipCannonballs.h"

MenuEquipCannonballs::MenuEquipCannonballs()
:ShipHandler()
{
    m_woodenMenu.setTexture(EQUIP_CANNONBALLS_WOOD);
    m_woodenMenu.setPosition(350, 100);

    m_stoneMenu.setTexture(EQUIP_CANNONBALLS_STONE);
    m_stoneMenu.setPosition(650, 100);

    m_cobbleStoneMenu.setTexture(EQUIP_CANNONBALLS_COBBLESTONE);
    m_cobbleStoneMenu.setPosition(950, 100);

    m_metalMenu.setTexture(EQUIP_CANNONBALLS_METAL);
    m_metalMenu.setPosition(350, 400);
}

void MenuEquipCannonballs::update(sf::Event const &event)
{
    m_woodenMenu.update(event);
    m_stoneMenu.update(event);
    m_cobbleStoneMenu.update(event);
    m_metalMenu.update(event);

    if (m_woodenMenu.getValue())
    {
        if (m_netWooden == 0)
        {
            m_netWooden = this->request(0, EQUIP_WOODEN_CANNONBALLS);
        }
        else if (m_netWooden == 1)
        {
            m_netWooden = this->request(1, EQUIP_WOODEN_CANNONBALLS);
        }
        else if (m_netWooden == 2)
        {

            m_ship->setCannonballs(WOODEN_CANNONBALLS_TYPE);
            m_woodenMenu.resetValue();

            m_packet->clear();
            m_netWooden= 0;
        }
    }
    else if (m_stoneMenu.getValue())
    {
        if (m_netStone == 0)
        {
            m_netStone = this->request(0, EQUIP_STONE_CANNONBALLS);
        }
        else if (m_netStone == 1)
        {
            m_netStone = this->request(1, EQUIP_STONE_CANNONBALLS);
        }
        else if (m_netStone == 2)
        {

            m_ship->setCannonballs(STONE_CANNONBALLS_TYPE);
            m_stoneMenu.resetValue();

            m_packet->clear();
            m_netStone = 0;
        }
    }
    else if (m_cobbleStoneMenu.getValue())
    {
        if (m_netCobbleStone == 0)
        {
            m_netCobbleStone = this->request(0, EQUIP_COBBLESTONE_CANNONBALLS);
        }
        else if (m_netCobbleStone == 1)
        {
            m_netCobbleStone = this->request(1, EQUIP_COBBLESTONE_CANNONBALLS);
        }
        else if (m_netCobbleStone == 2)
        {

            m_ship->setCannonballs(COBBLESTONE_CANNONBALLS_TYPE);
            m_cobbleStoneMenu.resetValue();

            m_packet->clear();
            m_netCobbleStone = 0;
        }
    }
    else if (m_metalMenu.getValue())
    {
        if (m_netMetal == 0)
        {
            m_netMetal = this->request(0, EQUIP_METAL_CANNONBALLS);
        }
        else if (m_netMetal == 1)
        {
            m_netMetal = this->request(1, EQUIP_METAL_CANNONBALLS);
        }
        else if (m_netMetal == 2)
        {

            m_ship->setCannonballs(METAL_CANNONBALLS_TYPE);
            m_metalMenu.resetValue();

            m_packet->clear();
            m_netMetal = 0;
        }
    }
}

void MenuEquipCannonballs::onComponentEvent(const sf::ui::ComponentEvent &event)
{

}

void MenuEquipCannonballs::render(sf::RenderTarget &target)
{
    m_woodenMenu.render(target),
    m_stoneMenu.render(target);
    m_cobbleStoneMenu.render(target);
    m_metalMenu.render(target);
}

MenuEquipCannonballs::~MenuEquipCannonballs()
{
    //dtor
}
