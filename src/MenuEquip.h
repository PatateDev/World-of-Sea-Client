#ifndef MENUEQUIP_H
#define MENUEQUIP_H

#include "../Main.h"
#include "Menu.h"

class MenuEquip : public Menu, public sf::ui::ComponentObserver
{
    public:

        MenuEquip();

        void setTexture(sf::Texture texture);
        void setTexture(sf::String link);

        void setPosition(int x, int y);

        void resetValue();

        int getValue();

        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        virtual ~MenuEquip();

    protected:
    private:
        sf::Texture m_textureButton, m_textureButtonFocus;
        sf::Texture m_textureSprite;

        sf::ui::Button m_button;
        sf::Sprite m_sprite;

        int m_value;
};

#endif // MENUEQUIP_H
