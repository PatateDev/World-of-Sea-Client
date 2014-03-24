#ifndef MENUBUYCANNONBALLS_H
#define MENUBUYCANNONBALLS_H

#include "MenuTrade.h"
#include "ShipHandler.h"
#include "../Config.h"

class MenuBuyCannonballs : public Menu, public sf::ui::ComponentObserver, public ShipHandler
{
    public:
        MenuBuyCannonballs();

        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        virtual ~MenuBuyCannonballs();
    protected:
    private:
        MenuTrade m_menuWoodenCannonballs;
        MenuTrade m_menuStoneCannonballs;
        MenuTrade m_menuCobbleStoneCannonballs;
        MenuTrade m_menuMetalCannonballs;

        int m_netWooden;
        int m_netStone;
        int m_netCobbleStone;
        int m_netMetal;

        int m_golds;
        int m_ammo;
        int m_ID;
};

#endif // MENUBUYCANNONBALLS_H
