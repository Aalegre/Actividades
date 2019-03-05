#pragma once
#include <iostream>

struct Board {
	Items **board;
	int stones, coins;
	int numRows,  numColumns;
	Board(int numRows_, int numColumns_) {
		board = new Items*[numRows_];
		for(int i = 0; i < numRows_; i++)
			board[i] = new Items[numColumns_];
		stones = 0;
		coins = 0;
		numRows = numRows_;
		numColumns = numColumns_;
	}

	void initialize(int maxStones, int maxCoins, Player &player) {
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numColumns; j++)
			{
				int rnd = rand() % numRows*numColumns;
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

		int i = rand() % numRows;
		int j = rand() % numColumns;
		//if (board[i][j] = STONE) stones--;
		//if (board[i][j] = COIN) coins--;
		////board[i][j] = PLAYER;
		player.position = { i, j };
	}

	void print() {
		std::cout << "\n";
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numColumns; j++)
			{
				if (board[i][j] == PLAYER)
				{
					std::cout << "\033[0;44m" << (char)board[i][j] << "\033[0;0m";
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
	void print(Vector2 playerPosition) {
		std::cout << "\n";
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numColumns; j++)
			{
				if (playerPosition.i == i && playerPosition.j == j)
				{
					std::cout << "\033[0;44m" << (char)PLAYER << "\033[0;0m";
				}
				else {
					std::cout << (char)board[i][j] << "";
				}
				//std::cout << (char)board[i][j] << "";
			}
			std::cout << "\n";
		}
	}

	bool checkMovement(Vector2 position, Movement move) {
		switch (move)
		{
		case UP:	return(position.i > 0			&& board[position.i - 1][position.j] != STONE);
		case DOWN:	return(position.i < numRows-1		&& board[position.i + 1][position.j] != STONE);
		case LEFT:	return(position.j > 0			&& board[position.i][position.j - 1] != STONE);
		case RIGHT:	return(position.j < numColumns-1	&& board[position.i][position.j + 1] != STONE);
		default:return false;
		}
		return false;
	}
	bool existsCoin(Vector2 position, Movement move) {
		switch (move)
		{
		case UP:	return(position.i > 0			&& board[position.i - 1][position.j] == COIN);
		case DOWN:	return(position.i < numRows-1		&& board[position.i + 1][position.j] == COIN);
		case LEFT:	return(position.j > 0			&& board[position.i][position.j - 1] == COIN);
		case RIGHT:	return(position.j < numColumns-1	&& board[position.i][position.j + 1] == COIN);
		}
		return false;
	}

	//void setPos(Vector2 oldPos, Vector2 newPos) {
	//	board[oldPos.i][newPos.j] = PATH;
	//	board[newPos.i][newPos.j] = PLAYER;
	//}
	//void setPos(Items oldItem, Vector2 oldPos, Items newItem, Vector2 newPos) {
	//	board[oldPos.i][newPos.j] = oldItem;
	//	board[newPos.i][newPos.j] = newItem;
	//}

	Vector2 movePlayer(Vector2 playerPosition, Movement move) {
		if (checkMovement(playerPosition, move)) {
			board[playerPosition.i][playerPosition.j] = PATH;
			switch (move)
			{
			case UP:	return Vector2(playerPosition.i - 1, playerPosition.j);
			case DOWN:	return Vector2(playerPosition.i + 1, playerPosition.j);
			case LEFT:	return Vector2(playerPosition.i, playerPosition.j - 1);
			case RIGHT:	return Vector2(playerPosition.i, playerPosition.j + 1);
			}
			return playerPosition;
		}
		else {
			return playerPosition;
		}
	}
};