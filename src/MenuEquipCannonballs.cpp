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

            m_packet->clear();
            *m_packet << EQUIP_CANNONBALLS_WOOD;
            m_socket->send(*m_packet);
            m_netWooden = 1;
        }
        else if (m_netWooden == 1)
        {
            delete m_packet;
            m_packet = m_networkReceive->getPacket(EQUIP_WOODEN_CANNONBALLS, *m_socket);

            if (m_packet)
            {
                m_netWooden = 2;
            }
            else
            {
                m_packet = new sf::Packet;
            }

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

            m_packet->clear();
            *m_packet << EQUIP_CANNONBALLS_STONE;
            m_socket->send(*m_packet);
            m_netStone = 1;
        }
        else if (m_netStone == 1)
        {
            delete m_packet;
            m_packet = m_networkReceive->getPacket(EQUIP_STONE_CANNONBALLS, *m_socket);

            if (m_packet)
            {
                m_netStone = 2;
            }
            else
            {
                m_packet = new sf::Packet;
            }

        }
        else if (m_netStone == 2)
        {

            m_ship->setCannonballs(STONE_CANNONBALLS_TYPE);
            m_woodenMenu.resetValue();

            m_packet->clear();
            m_netStone= 0;
        }
    }
    else if (m_cobbleStoneMenu.getValue())
    {
        m_ship->setCannonballs(COBBLESTONE_CANNONBALLS_TYPE);
        m_cobbleStoneMenu.resetValue();
    }
    else if (m_metalMenu.getValue())
    {
        m_ship->setCannonballs(METAL_CANNONBALLS_TYPE);
        m_metalMenu.resetValue();
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
