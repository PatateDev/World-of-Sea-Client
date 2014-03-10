#include "MenuEquipCannonballs.h"

MenuEquipCannonballs::MenuEquipCannonballs()
{
    m_woodenMenu.setTexture(MENU_EQUIP_CANNONBALLS_WOODEN);
    m_woodenMenu.setPosition(350, 100);

    m_stoneMenu.setTexture(MENU_EQUIP_CANNONBALLS_STONE);
    m_stoneMenu.setPosition(650, 100);

    m_cobbleStoneMenu.setTexture(MENU_EQUIP_CANNONBALLS_COBBLESTONE);
    m_cobbleStoneMenu.setPosition(950, 100);

    m_metalMenu.setTexture(MENU_EQUIP_CANNONBALLS_METAL);
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
