#include "Board.h"
#include "Block.h"

//void startGame();
void randomBlock(Block& block);
void previewBlock(Block& block, Block& previewBlock);
void swapBlock(Block& block, Block& perviewBlock);
//void placeBlock(Block& block, Board& board);
//bool isInBlock(Block block, Board board);
bool canMoveDown(Block block, Board board);
//void updateBlockRotation(Block& block);