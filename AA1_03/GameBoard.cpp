#include <iostream>
#include <ctime>

enum Movement { UP='w', DOWN='s', LEFT='a', RIGHT='d' };

const int NUM_ROWS = 25, NUM_COLUMNS = 80;
//const int NUM_ROWS = 10, NUM_COLUMNS = 10;
const int STONE_PERCENT = 20, COIN_PERCENT = 30;
int stones = 0, coins = 0;

enum Items { PATH='.', STONE ='#', COIN='$', PLAYER='@' };

Items board[NUM_ROWS][NUM_COLUMNS];

struct Player {
	int posI;
	int posJ;
	int score;
};

void initializeBoard(int maxStones, int maxCoins, Player player) {
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			int rnd = rand() % NUM_ROWS*NUM_COLUMNS;
			if (rnd <= maxStones && stones < maxStones) {
				board[i][j] = STONE;
				stones++;
			}
			else if (rnd > maxStones && rnd <= maxStones + maxCoins && coins < maxCoins) {
				board[i][j] = COIN;
				coins++;
			}
			else {
				board[i][j] = PATH;
			}
		}
	}

	int i = rand() % NUM_ROWS + 1;
	int j = rand() % NUM_COLUMNS + 1;
	if (board[i][j] = STONE) stones--;
	if (board[i][j] = COIN) coins--;
	board[i][j] = PLAYER;
	player.posI = i;
	player.posJ = j;
}

bool checkMovement(int posI, int posJ, Movement move) {
	switch (move)
	{
	case UP:	return(posI > 0				&& board[posI + 1][posJ] != STONE);
	case DOWN:	return(posI < NUM_ROWS		&& board[posI - 1][posJ] != STONE);
	case LEFT:	return(posJ > 0				&& board[posI][posJ - 1] != STONE);
	case RIGHT:	return(posJ < NUM_COLUMNS	&& board[posI][posJ + 1] != STONE);
	default:return false;
	}
	return false;
}

void updateScore(Player player) {
	player.score++;
}

void printBoard() {
	system("CLS");
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			if (board[i][j] == PLAYER) 
			{
				std::cout << "\033[0;31m" <<(char)board[i][j] << "\033[0;0m";
			}
			//else if (board[i][j] == COIN) 
			//{
			//	std::cout << "\033[1;33m" << (char)board[i][j] << "\033[0;0m";
			//}
			else {
				std::cout << (char)board[i][j] << "";
			}
			//std::cout << (char)board[i][j] << "";
		}
		std::cout << "\n";
	}
}

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
