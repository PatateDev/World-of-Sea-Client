#include "MenuEquipCannons.h"

MenuEquipCannons::MenuEquipCannons()
{
    m_lightCannon.setFont(FONT_PIECES_OF_EIGHT);
    m_lightCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_lightCannon.setLabelNameText("Light Cannon");
    m_lightCannon.setLabelImageTexture(CANNONS_LIGHT);
    m_lightCannon.setButtonTexture(MENU_BUTTON_EQUIP);
    m_lightCannon.setButtonTextureFocused(MENU_BUTTON_EQUIPFOCUS);
    m_lightCannon.setTextfieldTexture(MENU_TEXTFIELD2);
    m_lightCannon.setTextfieldTextureFocused(MENU_TEXTFIELDFOCUS2);
    m_lightCannon.setPosition(350, 100);

    m_heavyCannon.setFont(FONT_PIECES_OF_EIGHT);
    m_heavyCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_heavyCannon.setLabelNameText("Heavy Cannon");
    m_heavyCannon.setLabelImageTexture(CANNONS_HEAVY);
    m_heavyCannon.setButtonTexture(MENU_BUTTON_EQUIP);
    m_heavyCannon.setButtonTextureFocused(MENU_BUTTON_EQUIPFOCUS);
    m_heavyCannon.setTextfieldTexture(MENU_TEXTFIELD2);
    m_heavyCannon.setTextfieldTextureFocused(MENU_TEXTFIELDFOCUS2);
    m_heavyCannon.setPosition(800, 100);


}

void MenuEquipCannons::update(sf::Event const &event)
{
    m_lightCannon.update(event);
    m_heavyCannon.update(event);

    if (m_lightCannon.getValue() != 0)
    {
        Cannon c;
        c.setType("Light Cannon");
        c.setCannon(m_lightCannon.getValue());
        m_ship->setCannonEquiped(c);
        m_lightCannon.resetValue();
    }
    else if (m_heavyCannon.getValue() != 0)
    {
        Cannon c;
        c.setType("Heavy Cannon");
        c.setCannon(m_heavyCannon.getValue());
        m_ship->setCannonEquiped(c);
        m_heavyCannon.resetValue();
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
