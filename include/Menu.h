#ifndef MENU_H_
#define MENU_H_

class Menu;

#include "../Main.h"

/*
 * An abstract class that represent a game's menu
 * with its own components (button, text ...)
 */
class Menu
{

public:
	//CONSTRUCTORS/DESTRUCTOR --------------------------------------------
	/*
	 * Creates a menu
	 * Params:
	 * 	background - the backgrounds texture
	 */
	Menu(sf::Texture const& background);

	/*
	 * Creates a menu
	 * Params:
	 * 	background - the backgrounds sprite
	 */
	Menu(sf::Sprite const& background);

	virtual ~Menu();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
	/*
	 * Update the menu and its components
	 * Params:
	 * 	event - A SFML event
	 */
	virtual void update(sf::Event const &event) = 0;

	/*
	 * Render the menu by calling components' draw() function
	 * Params:
	 * 	target - the render target where draw components
	 */
	virtual void render(sf::RenderTarget &target) = 0;

	void setBackgroundTexture(sf::Texture background);
	void setBackgroundTexture(sf::String link);

	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
    sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	//--------------------------------------------------------------------
};

#endif /* MENU_H_ */
