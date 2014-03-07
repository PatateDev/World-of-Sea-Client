#include "MenuBuyCannons.h"

MenuBuyCannons::MenuBuyCannons()
{
    m_lightCannon.setFont("resources/fonts/Pieces of Eight.ttf");
    m_lightCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_lightCannon.setLabelNameText("Light Cannon");
    m_lightCannon.setLabelImageTexture("resources/sprites/lightCannon.png");
    m_lightCannon.setButtonTexture("resources/sprites/Bouton Buy2.png");
    m_lightCannon.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    m_lightCannon.setTextfieldTexture("resources/sprites/textfield.png");
    m_lightCannon.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
    m_lightCannon.setPosition(350, 100);

    m_heavyCannon.setFont("resources/fonts/Pieces of Eight.ttf");
    m_heavyCannon.setLabelDescriptionText("\n\nDescription\nDamage\nWeight\n$");
    m_heavyCannon.setLabelNameText("Heavy Cannon");
    m_heavyCannon.setLabelImageTexture("resources/sprites/heavyCannon.png");
    m_heavyCannon.setButtonTexture("resources/sprites/Bouton Buy2.png");
    m_heavyCannon.setButtonTextureFocused("resources/sprites/Bouton Buy2 focus.png");
    m_heavyCannon.setTextfieldTexture("resources/sprites/textfield.png");
    m_heavyCannon.setTextfieldTextureFocused("resources/sprites/textfieldFocus.png");
    m_heavyCannon.setPosition(800, 100);
}

void MenuBuyCannons::update(sf::Event const &event)
{
    m_lightCannon.update(event);
    m_heavyCannon.update(event);

    if ((m_lightCannon.getValue() != 0) && ((m_ship->getGolds() - (LIGHT_CANNON_PRICE * m_lightCannon.getValue())) > 0))
    {
        // BUY WOODEN CANNONBALLS
        m_ship->setGolds(m_ship->getGolds() - (LIGHT_CANNON_PRICE * m_lightCannon.getValue()));
        Cannon c;
        c.setType("Light Cannon");
        c.setCannon(m_lightCannon.getValue());
        m_ship->addCannon(c);
        m_lightCannon.resetValue();
    }
    else if ((m_heavyCannon.getValue() != 0) && ((m_ship->getGolds() - (HEAVY_CANNON_PRICE * m_heavyCannon.getValue())) > 0))
    {
        // BUY WOODEN CANNONBALLS
        m_ship->setGolds(m_ship->getGolds() - (HEAVY_CANNON_PRICE * m_heavyCannon.getValue()));
        Cannon c;
        c.setType("Heavy Cannon");
        c.setCannon(m_heavyCannon.getValue());
        m_ship->addCannon(c);
        m_heavyCannon.resetValue();
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
