#include "MenuTrade.h"

MenuTrade::MenuTrade()
:Menu(sf::Sprite()),
m_buttonBuy(m_buttonTexture, m_buttonTextureFocused, m_buttonTextureFocused),
m_textfield(m_textfieldTexture, m_textfieldTextureFocus, m_font, ""),
m_labelName()
{
    m_textfield.setModel(new sf::ui::NumericTextFieldModel());
    m_textfield.setCanBeEmpty(true);
    m_textfield.setFontColor(sf::Color::Black);
    m_textfield.setFontSize(30);
    m_textfield.setMaxLength(10);



    sf::Color marron(150, 150, 150);

    m_labelDescription.setFontColor(marron);
    m_labelName.setFontColor(marron);

    m_labelDescription.setFontSize(20);
}

void MenuTrade::update(sf::Event const &event)
{
    m_buttonBuy.updateEvent(event);

    m_textfield.updateEvent(event);

    m_labelName.updateEvent(event);
    m_labelDescription.updateEvent(event);
    m_labelImage.updateEvent(event);
}

void MenuTrade::onComponentEvent(const sf::ui::ComponentEvent &event)
{
    if (dynamic_cast<sf::ui::ButtonClickedEvent const*>(&event))
    {
		const sf::ui::ButtonClickedEvent &be = dynamic_cast<sf::ui::ButtonClickedEvent const&>(event);
		// Pour tester quel button a ete clique :

		  if (be.getSource() == &m_buttonBuy)
		  {
                std::istringstream(m_textfield.getText()) >> m_value;
          }
		  else
		  {
            std::cout << "Unknown button" << std::endl;
		  }
         //std::cout << "Menu: " << m_menu << std::endl;
		 std::cout << "Le button a l'addresse " << be.getSource() << " a été cliqué" << std::endl;
	}
}

void MenuTrade::render(sf::RenderTarget &target)
{
    target.draw(m_labelImage);
    target.draw(m_buttonBuy);

    target.draw(m_labelDescription);
    target.draw(m_labelName);

    target.draw(m_textfield);
}

// BUTTON TEXTURE
void MenuTrade::setButtonTexture(sf::Texture texture)
{
    m_buttonTexture = texture;
    m_buttonBuy.setTexture(m_buttonTexture);
}

void MenuTrade::setButtonTexture(sf::String link)
{
    m_buttonTexture.loadFromFile(link);
    m_buttonBuy.setTexture(m_buttonTexture);
}

void MenuTrade::setButtonTextureFocused(sf::Texture texture)
{
    m_buttonTextureFocused = texture;
}
void MenuTrade::setButtonTextureFocused(sf::String link)
{
    m_buttonTextureFocused.loadFromFile(link);
}

// TEXTFIELD TEXTURE

void MenuTrade::setTextfieldTexture(sf::Texture texture)
{
    m_textfieldTexture = texture;
    m_textfield.setTexture(m_textfieldTexture);
}

void MenuTrade::setTextfieldTexture(sf::String link)
{
    m_textfieldTexture.loadFromFile(link);
    m_textfield.setTexture(m_textfieldTexture);
}

void MenuTrade::setTextfieldTextureFocused(sf::Texture texture)
{
    m_textfieldTextureFocus = texture;
    m_textfield.setTextureFocused(m_textfieldTextureFocus);
}

void MenuTrade::setTextfieldTextureFocused(sf::String link)
{
    m_textfieldTextureFocus.loadFromFile(link);
    m_textfield.setTextureFocused(m_textfieldTextureFocus);
}

// LABEL TEXT

void MenuTrade::setLabelDescriptionText(sf::String text)
{
    m_labelDescription.setText(text);
}
void MenuTrade::setLabelNameText(sf::String text)
{
    m_labelName.setText(text);
}

// LABEL IMAGE

void MenuTrade::setLabelImageTexture(sf::Texture texture)
{
    m_labelImageTexture = texture;
    m_labelImage.setTexture(m_labelImageTexture);
}

void MenuTrade::setLabelImageTexture(sf::String link)
{
    m_labelImageTexture.loadFromFile(link);
    m_labelImage.setTexture(m_labelImageTexture);
}


// LABEL FONT

void MenuTrade::setFont(sf::Font font)
{
    m_font = font;

    m_labelName.setFont(m_font);
    m_labelDescription.setFont(m_font);
    m_textfield.setFont(m_font);
}

void MenuTrade::setFont(sf::String link)
{
    m_font.loadFromFile(link);

    m_labelName.setFont(m_font);
    m_labelDescription.setFont(m_font);

    m_textfield.setFont(m_font);
}

int MenuTrade::getValue()
{
    return m_value;
}

// POSITION

 void MenuTrade::setPosition(int x, int y)
 {
    m_buttonBuy.setPosition(x, y);
    m_textfield.setPosition(x, y);
    m_labelDescription.setPosition(x, y);
    m_labelName.setPosition(x, y);
    m_labelImage.setPosition(x, y);

    m_buttonBuy.move(m_textfield.getSize().x, m_labelImage.getSize().y);
    m_textfield.move(0, m_labelImage.getSize().y);
    m_labelDescription.move(m_labelImage.getSize().x/2, 50);
    m_labelName.move(50, 0);
    m_labelImage.move(0, 0);
 }

MenuTrade::~MenuTrade()
{
    //dtor
}
