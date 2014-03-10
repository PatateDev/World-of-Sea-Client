#include "MenuEquip.h"

MenuEquip::MenuEquip()
:Menu(sf::Sprite()),
m_button(m_textureButton, m_textureButtonFocus, m_textureButtonFocus),
m_value(0)
{
    m_button.addObserver(this);

    m_textureButton.loadFromFile(MENU_BUTTON_EQUIP);
    m_textureButtonFocus.loadFromFile(MENU_BUTTON_EQUIPFOCUS);

    m_button.updateSize();
}

void MenuEquip::update(sf::Event const &event)
{
    m_button.updateEvent(event);
}

void MenuEquip::onComponentEvent(const sf::ui::ComponentEvent &event)
{
    if (dynamic_cast<sf::ui::ButtonClickedEvent const*>(&event))
    {
		const sf::ui::ButtonClickedEvent &be = dynamic_cast<sf::ui::ButtonClickedEvent const&>(event);
		// Pour tester quel button a ete clique :

		  if (be.getSource() == &m_button)
		  {
            m_value = 1;
          }
		  else
		  {
            std::cout << "Unknown button" << std::endl;
		  }
         //std::cout << "Menu: " << m_menu << std::endl;
		 //std::cout << "Le button a l'addresse " << be.getSource() << " a ete clique" << std::endl;
	}
}

void MenuEquip::render(sf::RenderTarget &target)
{
    target.draw(m_button);
    target.draw(m_sprite);
}

void MenuEquip::setTexture(sf::Texture texture)
{
    m_textureSprite = texture;
    m_sprite.setTexture(m_textureSprite);
}

void MenuEquip::setTexture(sf::String link)
{
    m_textureSprite.loadFromFile(link);
    m_sprite.setTexture(m_textureSprite);
}

void MenuEquip::setPosition(int x, int y)
{
    m_sprite.setPosition(x, y);
    m_button.setPosition(x, y + 150);
}

void MenuEquip::resetValue()
{
    m_value = 0;
}

int MenuEquip::getValue()
{
    return m_value;
}

MenuEquip::~MenuEquip()
{
    //dtor
}
