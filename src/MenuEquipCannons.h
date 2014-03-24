#ifndef MENUEQUIPCANNONS_H
#define MENUEQUIPCANNONS_H

#include "../Main.h"
#include "ShipHandler.h"
#include "MenuTrade.h"

class MenuEquipCannons : public ShipHandler, sf::ui::ComponentObserver
{
    public:
        MenuEquipCannons();

        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        virtual ~MenuEquipCannons();
    protected:
    private:
        MenuTrade m_lightCannon;
        MenuTrade m_heavyCannon;

        int m_netLight;
        int m_netHeavy;

        int m_ID;
        int m_ammo;


};

#endif // MENUEQUIPCANNONS_H
