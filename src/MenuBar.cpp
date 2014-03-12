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
    m_font.loadFromFile(FONT_PIECES_OF_EIGHT);

    sf::Color yellow(180, 180, 0);

    m_labelGolds.setFont(m_font);
    m_labelGolds.setFontColor(yellow);
    m_labelGolds.setPosition(600, 0);
    m_labelGolds.setFontSize(60);

    m_buttonImgAccueil.loadFromFile(BUTTON_HOME);
    m_buttonFocImgAccueil.loadFromFile(BUTTON_HOME_FOCUS);

    m_buttonImgBuyCannons.loadFromFile(BUTTON_BUY_CANNONS);
    m_buttonFocImgBuyCannons.loadFromFile(BUTTON_BUY_CANNONS_FOCUS);

    m_buttonImgBuyCannonballs.loadFromFile(BUTTON_BUY_CANNONBALLS);
    m_buttonFocImgBuyCannonballs.loadFromFile(BUTTON_BUY_CANNONBALLS_FOCUS);

    m_buttonImgBuyDesigns.loadFromFile(BUTTON_BUY_DESIGNS);
    m_buttonFocImgBuyDesigns.loadFromFile(BUTTON_BUY_DESIGNS_FOCUS);

    m_buttonImgEquipCannonBalls.loadFromFile(BUTTON_EQUIP_CANNONBALLS);
    m_buttonFocImgEquipCannonballs.loadFromFile(BUTTON_EQUIP_CANNONBALLS_FOCUS);

    m_buttonImgEquipCannons.loadFromFile(BUTTON_EQUIP_CANNONS);
    m_buttonFocImgEquipCannons.loadFromFile(BUTTON_EQUIP_CANNONS_FOCUS);

    m_buttonImgEquipDesigns.loadFromFile(BUTTON_EQUIP_DESIGNS);
    m_buttonFocImgEquipDesigns.loadFromFile(BUTTON_EQUIP_DESIGNS_FOCUS);

    m_buttonImgExitGame.loadFromFile(BUTTON_EXIT);
    m_buttonFocImgExitGame.loadFromFile(BUTTON_EXIT_FOCUS);


    m_buttonAccueil.addObserver(this);
    m_buttonBuyCannonballs.addObserver(this);
    m_buttonBuyCannons.addObserver(this);
    m_buttonBuyDesign.addObserver(this);
    m_buttonEquipCannonBalls.addObserver(this);
    m_buttonEquipCannons.addObserver(this);
    m_buttonEquipDesign.addObserver(this);
    m_buttonExitGame.addObserver(this);

    m_buttonAccueil.updateSize();
    m_buttonBuyCannonballs.updateSize();
    m_buttonBuyCannons.updateSize();
    m_buttonBuyDesign.updateSize();
    m_buttonEquipCannonBalls.updateSize();
    m_buttonEquipCannons.updateSize();
    m_buttonEquipDesign.updateSize();
    m_buttonExitGame.updateSize();

    m_buttonAccueil.setPosition(0, 0);

    m_buttonBuyCannonballs.setPosition(0, 56+ 56);
    m_buttonBuyCannons.setPosition(0, 112+ 56);
    m_buttonBuyDesign.setPosition(0, 168+ 56);

    m_buttonEquipCannonBalls.setPosition(0, 224+ 56+ 56);
    m_buttonEquipCannons.setPosition(0, 280+ 56+ 56);
    m_buttonEquipDesign.setPosition(0, 336+ 56+ 56);

    m_buttonExitGame.setPosition(0, 392 + 56+ 56+ 56);

	m_backgroundTexture.loadFromFile(MENUBAR_BACKGROUND);
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

    m_labelGolds.updateEvent(event);
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

    m_labelGolds.setText(m_ship->getStrGolds());
    target.draw(m_labelGolds);
}

int MenuBar::getMenu()
{
    return m_menu;
}


MenuBar::~MenuBar()
{
    //dtor
}
