#include "Entity.h"

Entity::Entity()
{
	this->shape = new sf::CircleShape;
	this->rect = new sf::RectangleShape;
	this->scoreBoard = 0;
}

void Entity::loadText()
{
	// Load font
	font.loadFromFile("corbel.ttf");

	// select the font
	text.setFont(font); // font is a sf::Font

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	text.setString("Score: ");
    // set the color
	text.setColor(sf::Color::White);

	text.setPosition(sf::Vector2f(static_cast<float>(this->windowWidth - 800), static_cast<float>((this->windowHeight / 2) + 200)));
}

void Entity::updateText()
{
	text.setString("Score: " + std::to_string(this->scoreBoard));
}
