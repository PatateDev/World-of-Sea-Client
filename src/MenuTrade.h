#ifndef MENUTRADE_H
#define MENUTRADE_H

#include "Menu.h"

class MenuTrade : public Menu, public sf::ui::ComponentObserver
{
    public:
        MenuTrade();

        void setPosition(int x, int y);

        void setButtonTexture(sf::Texture texture);
        void setButtonTexture(sf::String link);
        void setButtonTextureFocused(sf::Texture texture);
        void setButtonTextureFocused(sf::String link);

        void setTextfieldTexture(sf::Texture texture);
        void setTextfieldTexture(sf::String link);
        void setTextfieldTextureFocused(sf::Texture texture);
        void setTextfieldTextureFocused(sf::String link);

        void setLabelDescriptionText(sf::String text);
        void setLabelNameText(sf::String text);
        void setLabelImageTexture(sf::Texture texture);
        void setLabelImageTexture(sf::String link);

        void setFont(sf::Font font);
        void setFont(sf::String link);

        int getValue();

        //
        virtual void update(sf::Event const &event);

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);

        virtual void render(sf::RenderTarget &target);

        virtual ~MenuTrade();
    protected:
    private:
        int m_value;

        sf::ui::Button m_buttonBuy;
        sf::Texture m_buttonTexture;
        sf::Texture m_buttonTextureFocused;

        sf::ui::Label m_labelDescription;
        sf::ui::Label m_labelName;
        sf::ui::Label m_labelImage;
        sf::Texture m_labelImageTexture;


        sf::ui::TextField m_textfield;
        sf::Texture m_textfieldTexture;
        sf::Texture m_textfieldTextureFocus;

        sf::Font m_font;
};

#endif // MENUTRADE_H
