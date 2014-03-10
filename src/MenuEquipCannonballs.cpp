#include "MenuEquipCannonballs.h"

MenuEquipCannonballs::MenuEquipCannonballs()
{
    m_woodenMenu.setTexture("resources/sprites/Boulet bois equip.png");
    m_woodenMenu.setPosition(350, 100);

    m_stoneMenu.setTexture("resources/sprites/Boulet pierre equip.png");
    m_stoneMenu.setPosition(650, 100);

    m_cobbleStoneMenu.setTexture("resources/sprites/Boulet beton equip.png");
    m_cobbleStoneMenu.setPosition(950, 100);

    m_metalMenu.setTexture("resources/sprites/Boulet metal equip.png");
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
        m_ship->setCannonballs("Wooden Ammo");
        m_woodenMenu.resetValue();
    }
    else if (m_stoneMenu.getValue())
    {
        m_ship->setCannonballs("Stone Ammo");
        m_stoneMenu.resetValue();
    }
    else if (m_cobbleStoneMenu.getValue())
    {
        m_ship->setCannonballs("Cobblestone Ammo");
        m_cobbleStoneMenu.resetValue();
    }
    else if (m_metalMenu.getValue())
    {
        m_ship->setCannonballs("Metal Ammo");
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
