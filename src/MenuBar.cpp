#include "MenuBar.h"

MenuBar::MenuBar()
:Menu(sf::Sprite()),
m_menu(0),
m_buttonAccueil(m_buttonImgAccueil, m_buttonFocImgAccueil, m_buttonFocImgAccueil),
m_buttonBuyCannonballs(m_buttonImgBuyCannonballs, m_buttonFocImgBuyCannonballs, m_buttonFocImgBuyCannonballs),
m_buttonBuyCannons(m_buttonImgBuyCannons, m_buttonFocImgBuyCannons, m_buttonFocImgBuyCannons),
m_buttonBuyDesign(m_buttonImgBuyDesigns, m_buttonFocImgBuyDesigns, m_buttonImgBuyDesigns),
m_buttonEquipCannonBalls(m_buttonImgEquipCannonBalls, m_buttonFocImgEquipCannonballs, m_buttonFocImgEquipCannonballs),
m_buttonEquipCannons(m_buttonImgEquipCannons, m_buttonFocImgEquipCannons, m_buttonFocImgEquipCannons),
m_buttonEquipDesign(m_buttonImgEquipDesigns, m_buttonFocImgEquipDesigns, m_buttonFocImgEquipDesigns),
m_buttonExitGame(m_buttonImgExitGame, m_buttonFocImgExitGame, m_buttonFocImgExitGame)
{
    m_buttonImgAccueil.loadFromFile("resources/sprites/Bouton Home.png");
    m_buttonFocImgAccueil.loadFromFile("resources/sprites/Bouton Home focus.png");
    m_buttonFirImgAccueil.loadFromFile("resources/sprites/Bouton Home focus.png");

    m_buttonImgBuyCannons.loadFromFile("resources/sprites/Bouton buy cannons.png");
    m_buttonFocImgBuyCannons.loadFromFile("resources/sprites/Bouton buy cannons focus.png");
    m_buttonFirImgCannons.loadFromFile("resources/sprites/Bouton buy cannons focus.png");


    m_buttonImgBuyCannonballs.loadFromFile("resources/sprites/Bouton buy cannonballs.png");
    m_buttonFocImgBuyCannonballs.loadFromFile("resources/sprites/Bouton buy cannonballs focus.png");
    m_buttonFirImgCannonballs.loadFromFile("resources/sprites/Bouton buy cannonballs focus.png");

    m_buttonImgBuyDesigns.loadFromFile("resources/sprites/Bouton buy designs.png");
    m_buttonFocImgBuyDesigns.loadFromFile("resources/sprites/Bouton buy designs focus.png");

    m_buttonImgEquipCannonBalls.loadFromFile("resources/sprites/Bouton equip Cannonballs.png");
    m_buttonFocImgEquipCannonballs.loadFromFile("resources/sprites/Bouton equip Cannonballs focus.png");

    m_buttonImgEquipCannons.loadFromFile("resources/sprites/Bouton equip cannon.png");
    m_buttonFocImgEquipCannons.loadFromFile("resources/sprites/Bouton equip cannon focus.png");

    m_buttonImgEquipDesigns.loadFromFile("resources/sprites/Bouton equip design.png");
    m_buttonFocImgEquipDesigns.loadFromFile("resources/sprites/Bouton equip design focus.png");

    m_buttonImgExitGame.loadFromFile("resources/sprites/Bouton Exit.png");
    m_buttonFocImgExitGame.loadFromFile("resources/sprites/Bouton Exit focus.png");


    m_buttonAccueil.addObserver(this);
    m_buttonBuyCannonballs.addObserver(this);
    m_buttonBuyCannons.addObserver(this);
    m_buttonBuyDesign.addObserver(this);
    m_buttonEquipCannonBalls.addObserver(this);
    m_buttonEquipCannons.addObserver(this);
    m_buttonEquipDesign.addObserver(this);
    m_buttonExitGame.addObserver(this);

    m_buttonAccueil.setTexture(m_buttonImgAccueil);
    m_buttonBuyCannonballs.setTexture(m_buttonImgBuyCannonballs);
    m_buttonBuyCannons.setTexture(m_buttonImgBuyCannons);
    m_buttonBuyDesign.setTexture(m_buttonImgBuyDesigns);
    m_buttonEquipCannonBalls.setTexture(m_buttonImgEquipCannonBalls);
    m_buttonEquipCannons.setTexture(m_buttonImgEquipCannons);
    m_buttonEquipDesign.setTexture(m_buttonImgEquipDesigns);
    m_buttonExitGame.setTexture(m_buttonImgExitGame);

    m_buttonAccueil.setPosition(0, 0);

    m_buttonBuyCannonballs.setPosition(0, 56+ 56);
    m_buttonBuyCannons.setPosition(0, 112+ 56);
    m_buttonBuyDesign.setPosition(0, 158+ 56);

    m_buttonEquipCannonBalls.setPosition(0, 214+ 56+ 56);
    m_buttonEquipCannons.setPosition(0, 270+ 56+ 56);
    m_buttonEquipDesign.setPosition(0, 326+ 56+ 56);

    m_buttonExitGame.setPosition(0, 382 + 56+ 56+ 56);

	m_backgroundTexture.loadFromFile("resources/sprites/Background.bmp");
	m_labelBackground.setTexture(m_backgroundTexture);
	m_labelBackground.setPosition(0, 0);


}

void MenuBar::update(sf::Event const &event)
{
    m_buttonAccueil.updateEvent(event);
    m_buttonBuyCannonballs.updateEvent(event);
    m_buttonBuyCannons.updateEvent(event);
    m_buttonBuyDesign.updateEvent(event);
    m_buttonEquipCannonBalls.updateEvent(event);
    m_buttonEquipCannons.updateEvent(event);
    m_buttonEquipDesign.updateEvent(event);
    m_buttonExitGame.updateEvent(event);
}

void MenuBar::onComponentEvent(const sf::ui::ComponentEvent &event)
{
    if (dynamic_cast<sf::ui::ButtonClickedEvent const*>(&event))
    {
		const sf::ui::ButtonClickedEvent &be = dynamic_cast<sf::ui::ButtonClickedEvent const&>(event);

		if (be.getSource() == &m_buttonAccueil)
		{
		    m_menu = 0;
		}
		else if (be.getSource() == &m_buttonBuyCannonballs)
		{
		    m_menu = 1;
		}
		else if (be.getSource() == &m_buttonBuyCannons)
		{
		    m_menu = 2;
		}
		else if (be.getSource() == &m_buttonBuyDesign)
		{
		    m_menu = 3;
		}
		else if (be.getSource() == &m_buttonEquipCannonBalls)
		{
		    m_menu = 4;
		}
		else if (be.getSource() == &m_buttonEquipCannons)
		{
		    m_menu = 5;
		}
		else if (be.getSource() == &m_buttonEquipDesign)
		{
		    m_menu = 6;
		}
		else if (be.getSource() == &m_buttonExitGame)
		{
		    m_menu = 7;
		}
		else
		{
		    std::cout << "Unknown button" << std::endl;
		}
	}
}

void MenuBar::render(sf::RenderTarget &target)
{
    target.draw(m_labelBackground);

    target.draw(m_buttonAccueil);
    target.draw(m_buttonBuyCannonballs);
    target.draw(m_buttonBuyCannons);
    target.draw(m_buttonBuyDesign);
    target.draw(m_buttonEquipCannonBalls);
    target.draw(m_buttonEquipCannons);
    target.draw(m_buttonEquipDesign);
    target.draw(m_buttonExitGame);
}

int MenuBar::getMenu()
{
    return m_menu;
}


MenuBar::~MenuBar()
{
    //dtor
}
