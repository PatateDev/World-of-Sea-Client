#ifndef MENUEQUIPCANNONBALLS_H
#define MENUEQUIPCANNONBALLS_H

#include "ShipHandler.h"
#include "MenuEquip.h"

class MenuEquipCannonballs : public ShipHandler, public sf::ui::ComponentObserver
{
    public:
        MenuEquipCannonballs();

        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        virtual ~MenuEquipCannonballs();
    protected:
    private:
        MenuEquip m_woodenMenu;
        MenuEquip m_stoneMenu;
        MenuEquip m_cobbleStoneMenu;
        MenuEquip m_metalMenu;
};

#endif // MENUEQUIPCANNONBALLS_H
