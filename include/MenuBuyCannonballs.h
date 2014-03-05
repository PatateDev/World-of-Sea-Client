#ifndef MENUBUYCANNONBALLS_H
#define MENUBUYCANNONBALLS_H

#include "MenuTrade.h"

class MenuBuyCannonballs : public Menu, public sf::ui::ComponentObserver
{
    public:
        MenuBuyCannonballs();

        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        virtual ~MenuBuyCannonballs();
    protected:
    private:
        MenuTrade menuTrade;
};

#endif // MENUBUYCANNONBALLS_H
