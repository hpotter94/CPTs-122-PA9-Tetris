#include <SFML/Graphics.hpp>

const sf::Vector2f bSize(30, 30); //Square size
const sf::Vector2f bStart(200, 100); //Start Coordinates (Change Probably)
const int start_x = 4;
const int start_y = 0;

class Square : public sf::RectangleShape //Create squre used for each Block
{
public:
	Square() {}
	Square(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color) : sf::RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}
};

class Block //Each Block contains four squares
{
protected:
	Square central_block; //Central square that is rotated around
	int central_coordinates[2];
	int side_block[3][2]; //Denotes where the three other blocks are relative to the central block
public:
	Block() {}
	Block(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color)
	{
		Square newSquare(size, position, color);
		central_block = newSquare;

		side_block[0][0] = 0;
		side_block[0][1] = 0;
		side_block[1][0] = 0;
		side_block[1][1] = 0;
		side_block[2][0] = 0;
		side_block[2][1] = 0;

		central_coordinates[0] = start_x;
		central_coordinates[1] = start_y;
	}
	~Block() {}
	void drop();
	void rotateR();
	void rotateL();
	void moveR();
	void moveL();
	void setPosition(sf::Vector2f& position);
	void setPosition(int X, int Y);
	void draw(sf::RenderWindow& window);
};

class OBlock : public Block //Below are the different types of Blocks, with the only difference being positions of side blocks and color
{
private:

public:
	OBlock(const sf::Vector2f& position) : Block(bSize, position, sf::Color::Yellow)
	{
		side_block[0][0] = 1;
		side_block[0][1] = 0;

		side_block[1][0] = 0;
		side_block[1][1] = -1;
		
		side_block[2][0] = 1;
		side_block[2][1] = -1;
	}
};

class TBlock : public Block
{
public:
	TBlock(const sf::Vector2f& position) : Block(bSize, position, sf::Color::Magenta)
	{
		side_block[0][0] = 1;
		side_block[0][1] = 0;

		side_block[1][0] = -1;
		side_block[1][1] = 0;

		side_block[2][0] = 0;
		side_block[2][1] = -1;
	}
};

class LBlock : public Block
{
public:
	LBlock(const sf::Vector2f& position) : Block(bSize, position, sf::Color(255, 102, 0 , 255))
	{
		side_block[0][0] = 0;
		side_block[0][1] = 1;

		side_block[1][0] = 1;
		side_block[1][1] = 0;

		side_block[2][0] = 2;
		side_block[2][1] = 0;
	}
};

class JBlock : public Block
{
public:
	JBlock(const sf::Vector2f& position) : Block(bSize, position, sf::Color::Blue)
	{
		side_block[0][0] = 0;
		side_block[0][1] = -1;

		side_block[1][0] = 1;
		side_block[1][1] = 0;

		side_block[2][0] = 2;
		side_block[2][1] = 0;
	}
};

class IBlock : public Block
{
public:
	IBlock(const sf::Vector2f& position) : Block(bSize, position, sf::Color::Cyan)
	{
		side_block[0][0] = -1;
		side_block[0][1] = 0;

		side_block[1][0] = 1;
		side_block[1][1] = 0;

		side_block[2][0] = 2;
		side_block[2][1] = 0;
	}
};

class SBlock : public Block
{
public:
	SBlock(const sf::Vector2f& position) : Block(bSize, position, sf::Color::Green)
	{
		side_block[0][0] = -1;
		side_block[0][1] = 0;

		side_block[1][0] = 1;
		side_block[1][1] = -1;

		side_block[2][0] = 0;
		side_block[2][1] = -1;
	}
};

class ZBlock : public Block
{
public:
	ZBlock(const sf::Vector2f& position) : Block(bSize, position, sf::Color::Red)
	{
		side_block[0][0] = 1;
		side_block[0][1] = 0;

		side_block[1][0] = -1;
		side_block[1][1] = -1;

		side_block[2][0] = 0;
		side_block[2][1] = -1;
	}
};