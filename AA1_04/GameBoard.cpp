#include <iostream>
#include <ctime>
#include "Constants.h"
#include "Types.h"
#include "Board.h"
#include "Player.h"


const int NUM_ROWS = 25, NUM_COLUMNS = 80;



Items board[NUM_ROWS][NUM_COLUMNS];








void main() {
	time_t t;
	srand((unsigned)time(&t));

	Player p1 = { 0,0,0 };

	initializeBoard(
		((NUM_ROWS*NUM_COLUMNS) * (float)(STONE_PERCENT / (float)100)), 
		((NUM_ROWS*NUM_COLUMNS) * (float)(COIN_PERCENT / (float)100)), 
		p1);
	printBoard();
}
