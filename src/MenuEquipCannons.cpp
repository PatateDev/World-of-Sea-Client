#include "MenuEquipCannons.h"

MenuEquipCannons::MenuEquipCannons()
:ShipHandler(),
m_netLight(0),
m_netHeavy(0),
m_ammo(0)
{
    m_lightCannon.setFont(FONT_PIECES_OF_EIGHT);
    m_lightCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_lightCannon.setLabelNameText(LIGHT_CANNON_TYPE);
    m_lightCannon.setLabelImageTexture(CANNONS_LIGHT);
    m_lightCannon.setButtonTexture(BUTTON_EQUIP);
    m_lightCannon.setButtonTextureFocused(BUTTON_EQUIP_FOCUS);
    m_lightCannon.setTextfieldTexture(TEXTFIELD_2);
    m_lightCannon.setTextfieldTextureFocused(TEXTFIELD_2_FOCUS);
    m_lightCannon.setPosition(350, 100);

    m_heavyCannon.setFont(FONT_PIECES_OF_EIGHT);
    m_heavyCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_heavyCannon.setLabelNameText(HEAVY_CANNON_TYPE);
    m_heavyCannon.setLabelImageTexture(CANNONS_HEAVY);
    m_heavyCannon.setButtonTexture(BUTTON_EQUIP);
    m_heavyCannon.setButtonTextureFocused(BUTTON_EQUIP_FOCUS);
    m_heavyCannon.setTextfieldTexture(TEXTFIELD_2);
    m_heavyCannon.setTextfieldTextureFocused(TEXTFIELD_2_FOCUS);
    m_heavyCannon.setPosition(800, 100);


}

void MenuEquipCannons::update(sf::Event const &event)
{
    m_lightCannon.update(event);
    m_heavyCannon.update(event);

    if (m_lightCannon.getValue() != 0)
    {
        if (m_netLight == 0)
        {
            m_packet->clear();
            *m_packet << EQUIP_LIGHT_CANNONS << m_lightCannon.getValue();
            m_socket->send(*m_packet);
            m_netLight = 1;
        }
        else if (m_netLight == 1)
        {
            delete m_packet;
            m_packet = m_networkReceive->getPacket(EQUIP_LIGHT_CANNONS, *m_socket);

            if (m_packet)
            {
                m_netLight = 2;
            }
            else
            {
                m_packet = new sf::Packet;
            }

        }
        else if (m_netLight == 2)
        {
            *m_packet >> m_ammo;

            Cannon c;
            c.setType(LIGHT_CANNON_TYPE);
            c.setCannon(m_ammo);

            m_ship->setCannonEquiped(c);

            m_lightCannon.resetValue();
            m_packet->clear();
            m_netLight = 0;
        }


    }
    else if (m_heavyCannon.getValue() != 0)
    {
        if (m_netHeavy == 0)
        {
            m_packet->clear();
            *m_packet << EQUIP_HEAVY_CANNONS << m_heavyCannon.getValue();
            m_socket->send(*m_packet);
            m_netHeavy = 1;
        }
        else if (m_netHeavy == 1)
        {
            delete m_packet;
            m_packet = m_networkReceive->getPacket(EQUIP_HEAVY_CANNONS, *m_socket);

            if (m_packet)
            {
                m_netHeavy = 2;

            }
            else
            {
                m_packet = new sf::Packet;
            }

        }
        else if (m_netHeavy == 2)
        {
            *m_packet >> m_ammo;

            Cannon c;
            c.setType(HEAVY_CANNON_TYPE);
            c.setCannon(m_ammo);

            m_ship->setCannonEquiped(c);

            m_heavyCannon.resetValue();
            m_packet->clear();
            m_netHeavy = 0;
        }
    }


}

void MenuEquipCannons::onComponentEvent(const sf::ui::ComponentEvent &event)
{

}

void MenuEquipCannons::render(sf::RenderTarget &target)
{
    m_lightCannon.render(target);
    m_heavyCannon.render(target);
}

MenuEquipCannons::~MenuEquipCannons()
{
    //dtor
}
