#ifndef DESIGN_H
#define DESIGN_H

#include "../Main.h"

class Design
{
    public:
        Design();

        void setName(std::string name);

        void setTexture(sf::Texture texture);
        void setTexture(sf::String textureLink);

        sf::Texture getTexture();
        std::string getName();

        virtual ~Design();
    protected:
    private:
        sf::Texture m_texture;

        std::string m_name;
};

#endif // DESIGN_H
