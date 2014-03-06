#ifndef MENUBAR_H
#define MENUBAR_H

#include "Menu.h"
#include "ShipHandler.h"

class MenuBar : public Menu, public sf::ui::ComponentObserver, public ShipHandler
{
    public:
        MenuBar();

        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        int getMenu();

        virtual ~MenuBar();
    protected:
    private:
    int m_menu;

    sf::Texture m_buttonImgAccueil;
    sf::Texture m_buttonImgBuyCannons;
    sf::Texture m_buttonImgBuyCannonballs;
    sf::Texture m_buttonImgBuyDesigns;
    sf::Texture m_buttonImgEquipCannons;
    sf::Texture m_buttonImgEquipCannonBalls;
    sf::Texture m_buttonImgEquipDesigns;
    sf::Texture m_buttonImgExitGame;

    sf::Texture m_buttonFocImgAccueil;
    sf::Texture m_buttonFocImgBuyCannons;
    sf::Texture m_buttonFocImgBuyCannonballs;
    sf::Texture m_buttonFocImgBuyDesigns;
    sf::Texture m_buttonFocImgEquipCannons;
    sf::Texture m_buttonFocImgEquipCannonballs;
    sf::Texture m_buttonFocImgEquipDesigns;
    sf::Texture m_buttonFocImgExitGame;

    sf::Texture m_buttonFirImgAccueil;
    sf::Texture m_buttonFirImgCannons;
    sf::Texture m_buttonFirImgCannonballs;

    sf::ui::Button m_buttonAccueil;
    sf::ui::Button m_buttonBuyCannons;
    sf::ui::Button m_buttonBuyCannonballs;
    sf::ui::Button m_buttonBuyDesign;
    sf::ui::Button m_buttonEquipCannons;
    sf::ui::Button m_buttonEquipCannonBalls;
    sf::ui::Button m_buttonEquipDesign;
    sf::ui::Button m_buttonExitGame;
    //
    sf::ui::Label m_labelBackground;
    sf::ui::Label m_labelGolds;

    sf::Texture m_textureBackground;
    sf::Font m_font;

};

#endif // MENUBAR_H
