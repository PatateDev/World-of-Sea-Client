#ifndef MENUBUYCANNONS_H
#define MENUBUYCANNONS_H

#include "ShipHandler.h"
#include "MenuTrade.h"

class MenuBuyCannons : public ShipHandler, public sf::ui::ComponentObserver
{
    public:
        MenuBuyCannons();

        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        virtual ~MenuBuyCannons();
    protected:
    private:
        MenuTrade m_lightCannon;
        MenuTrade m_heavyCannon;
};

#endif // MENUBUYCANNONS_H
