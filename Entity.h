#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

#pragma once
class Entity
{
public:
	Entity();
	~Entity() {}
	void loadText();
	void updateText();

public:
	int windowWidth = 800;
    int windowHeight = 600;
	int scoreBoard;

	bool gameOver = true;

// Need to put them in entity so we can access them.
public:
	float blockWidth = 60.0f;
	float blockHeight = 60.0f;

public:
	sf::CircleShape* shape;
	sf::RectangleShape* rect;
	sf::Font font;
	sf::Text text;

private:

};

