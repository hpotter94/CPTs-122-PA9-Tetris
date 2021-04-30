#pragma once
#include"SFML/Graphics.hpp"

const sf::Vector2f bSize(30, 30); //Square size

class Square : public sf::RectangleShape //Create squre used for each Block
{
public:
	Square() {}
	Square(const sf::Vector2f& pos, const sf::Color& color) : sf::RectangleShape(bSize)
	{
		this->setFillColor(color);
		this->setPosition(pos);
		this->setOutlineColor(sf::Color::White);
		this->setOutlineThickness(1);
	}
};