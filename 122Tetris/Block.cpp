#include "Block.h"

void Block::drop() //Go down thirty (one square space)
{
	central_block.move(0, 30);
	central_coordinates[1]++;
}

void Block::rotateL() //Rotate counter-clockwise
{
	int p = -side_block[0][0];
	side_block[0][0] = side_block[0][1];
	side_block[0][1] = p;

	p = -side_block[1][0];
	side_block[1][0] = side_block[1][1];
	side_block[1][1] = p;

	p = -side_block[2][0];
	side_block[2][0] = side_block[2][1];
	side_block[2][1] = p;
}

void Block::rotateR() //Rotate clockwise
{
	int p = side_block[0][0];
	side_block[0][0] = -side_block[0][1];
	side_block[0][1] = p;

	p = side_block[1][0];
	side_block[1][0] = -side_block[1][1];
	side_block[1][1] = p;

	p = side_block[2][0];
	side_block[2][0] = -side_block[2][1];
	side_block[2][1] = p;
}

void Block::moveL() //Move one square space to the left
{
	central_block.move(-30, 0);
	central_coordinates[0]--;
}

void Block::moveR() //Move one square space to the left
{
	central_block.move(30, 0);
	central_coordinates[0]++;
}

void Block::setPosition(sf::Vector2f& position) //Set the position of the block
{
	central_block.setPosition(position);
}

void Block::setPosition(int X, int Y)
{
	central_block.setPosition(sf::Vector2f(X, Y));
}
void Block::draw(sf::RenderWindow& window) //Draw the block
{
	window.draw(central_block);
	for (int i = 0; i < 3; i++)
	{
		Square r = central_block;
		r.setPosition(sf::Vector2f(30 * side_block[i][0], 30 * side_block[i][1]) + central_block.getPosition());
		window.draw(r);
	}
}