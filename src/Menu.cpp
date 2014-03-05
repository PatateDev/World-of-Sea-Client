#include "Menu.h"

Menu::Menu(const sf::Texture& background)
: m_backgroundSprite(background)
{

}

Menu::Menu(const sf::Sprite& background)
: m_backgroundSprite(background)
{

}

void Menu::setBackgroundTexture(sf::Texture background)
{
    m_backgroundTexture = background;
    m_backgroundSprite.setTexture(m_backgroundTexture);
}

void Menu::setBackgroundTexture(sf::String link)
{
    m_backgroundTexture.loadFromFile(link);
    m_backgroundSprite.setTexture(m_backgroundTexture);
}

Menu::~Menu()
{

}

