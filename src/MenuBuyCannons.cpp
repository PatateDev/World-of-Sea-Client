#include "MenuBuyCannons.h"

MenuBuyCannons::MenuBuyCannons()
:ShipHandler(),
m_netLight(0),
m_netHeavy(0)
{
    m_lightCannon.setFont(FONT_PIECES_OF_EIGHT);
    m_lightCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_lightCannon.setLabelNameText(LIGHT_CANNON_TYPE);
    m_lightCannon.setLabelImageTexture(CANNONS_LIGHT);
    m_lightCannon.setButtonTexture(BUTTON_BUY);
    m_lightCannon.setButtonTextureFocused(BUTTON_BUY_FOCUS);
    m_lightCannon.setTextfieldTexture(TEXTFIELD_1);
    m_lightCannon.setTextfieldTextureFocused(TEXTFIELD_1_FOCUS);
    m_lightCannon.setPosition(350, 100);

    m_heavyCannon.setFont(FONT_PIECES_OF_EIGHT);
    m_heavyCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_heavyCannon.setLabelNameText(HEAVY_CANNON_TYPE);
    m_heavyCannon.setLabelImageTexture(CANNONS_HEAVY);
    m_heavyCannon.setButtonTexture(BUTTON_BUY);
    m_heavyCannon.setButtonTextureFocused(BUTTON_BUY_FOCUS);
    m_heavyCannon.setTextfieldTexture(TEXTFIELD_1);
    m_heavyCannon.setTextfieldTextureFocused(TEXTFIELD_1_FOCUS);
    m_heavyCannon.setPosition(800, 100);
}

void MenuBuyCannons::update(sf::Event const &event)
{
    m_lightCannon.update(event);
    m_heavyCannon.update(event);

    if (m_lightCannon.getValue() != 0)
    {
        // BUY LIGHT CANNONBALLS
        if (m_netLight == 0)
        {
            m_netLight = this->request(0, BUY_LIGHT_CANNONS, m_lightCannon.getValue());
        }
        else if (m_netLight == 1)
        {
            m_netLight = this->request(1, BUY_LIGHT_CANNONS, m_lightCannon.getValue());
        }
        else if (m_netLight == 2)
        {
            *m_packet >> m_ammo >> m_golds;

            Cannon c;
            c.setType(LIGHT_CANNON_TYPE);
            c.setCannon(m_ammo);

            m_ship->addCannon(c);
            m_ship->setGolds(m_golds);

            //std::cout << "Ammo: " << m_ammo << " Golds: " << m_ship->getGolds() << std::endl;

            m_lightCannon.resetValue();
            m_packet->clear();
            m_netLight = 0;
        }

    }
    else if (m_heavyCannon.getValue() != 0)
    {
        // BUY HEAVY CANNONBALLS
        if (m_netHeavy == 0)
        {
            m_netHeavy = this->request(0, BUY_HEAVY_CANNONS, m_heavyCannon.getValue());
        }
        else if (m_netHeavy == 1)
        {
            m_netHeavy = this->request(1, BUY_HEAVY_CANNONS, m_heavyCannon.getValue());
        }
        else if (m_netHeavy == 2)
        {
            *m_packet >> m_ammo >> m_golds;

            Cannon c;
            c.setType(HEAVY_CANNON_TYPE);
            c.setCannon(m_ammo);

            m_ship->addCannon(c);
            m_ship->setGolds(m_golds);

            //std::cout << "Ammo: " << m_ammo << " Golds: " << m_ship->getGolds() << std::endl;

            m_heavyCannon.resetValue();
            m_packet->clear();
            m_netHeavy = 0;
        }
    }

}

void MenuBuyCannons::onComponentEvent(const sf::ui::ComponentEvent &event)
{

}

void MenuBuyCannons::render(sf::RenderTarget &target)
{
    m_lightCannon.render(target);
    m_heavyCannon.render(target);
}

MenuBuyCannons::~MenuBuyCannons()
{
    //dtor
}
