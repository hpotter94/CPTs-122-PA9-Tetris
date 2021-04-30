#include "Square.h"

#define xSpaces 10
#define ySpaces 24

class Board
{
private:
	Square board[xSpaces][ySpaces];
public:
	Board()
	{
		for (int i = 0; i < xSpaces; i++)
		{
			for (int j = 0; j < ySpaces; j++)
			{
				board[i][j].setFillColor(sf::Color::Transparent);
			}
		}
	}

	void print();
};