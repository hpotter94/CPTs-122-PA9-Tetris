#include "Tetris.h"

void randomBlock(Block& block)
{
	srand(time(NULL)); //Random seed, might not need when added to rest of project

	int rand_block = rand() % 7;
	switch (rand_block)
	{
	case 0:
		block = IBlock(bStart);
		break;
	case 1:
		block = JBlock(bStart);
		break;
	case 2:
		block = LBlock(bStart);
		break;
	case 3:
		block = SBlock(bStart);
		break;
	case 4:
		block = ZBlock(bStart);
		break;
	case 5:
		block = TBlock(bStart);
		break;
	case 6:
		block = OBlock(bStart);
		break;
	}
}

void previewBlock(Block& block, Block& previewBlock)
{
	Block newBlock; // New block for generation
	randomBlock(newBlock); //Randomly selects block type
	block = previewBlock; // Sets the active block to what the preview block is
	previewBlock = newBlock; //Sets a new previewed block
}

void swapBlock(Block& block, Block& previewBlock)
{
	Block tempBlock; // For storing the current block
	tempBlock = block; // stores the currenty block into tempBlock
	block = previewBlock; //Changes the active block into the previewed block
	previewBlock = tempBlock; //Changes the preview block into what the active block was
}

bool canMoveDown(Block block, Board board)
{

}