#include "Design.h"

Design::Design()
:m_name("NULL")
{
    //ctor
}

void Design::setName(std::string name)
{
    m_name = name;
}

void Design::setTexture(sf::Texture texture)
{
      m_texture = texture;
}

void Design::setTexture(sf::String textureLink)
{
    m_texture.loadFromFile(textureLink);
}

//

sf::Texture Design::getTexture()
{
    return m_texture;
}

 std::string Design::getName()
 {
     return m_name;
 }

Design::~Design()
{
    //dtor
}
