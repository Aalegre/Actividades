#pragma once
#include <iostream>

struct Board {
	Items **board;
	unsigned int stones, coins;
	unsigned int numRows,  numColumns;
	Board(unsigned int numRows_, unsigned int numColumns_) {
		for(int i = 0; i < numRows_; i++)
			board[i] = new Items[numColumns_];
		stones = 0;
		coins = 0;
		numRows = numRows_;
		numColumns = numColumns_;
	}

	void initializeBoard(int maxStones, int maxCoins, Player player) {
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < NUM_COLUMNS; j++)
			{
				int rnd = rand() % numRows*NUM_COLUMNS;
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

	void printBoard() {
		system("CLS");
		for (int i = 0; i < NUM_ROWS; i++)
		{
			for (int j = 0; j < NUM_COLUMNS; j++)
			{
				if (board[i][j] == PLAYER)
				{
					std::cout << "\033[0;31m" << (char)board[i][j] << "\033[0;0m";
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

	bool checkMovement(int posI, int posJ, Movement move) {
		switch (move)
		{
		case UP:	return(posI > 0 && board[posI + 1][posJ] != STONE);
		case DOWN:	return(posI < NUM_ROWS		&& board[posI - 1][posJ] != STONE);
		case LEFT:	return(posJ > 0 && board[posI][posJ - 1] != STONE);
		case RIGHT:	return(posJ < NUM_COLUMNS	&& board[posI][posJ + 1] != STONE);
		default:return false;
		}
		return false;
	}
};