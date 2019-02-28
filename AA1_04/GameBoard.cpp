#include <iostream>
#include <ctime>
#include "Constants.h"
#include "Types.h"
#include "Player.h"
#include "Board.h"


void main() {
	srand((unsigned)time(new time_t));

	int columns, rows;
	std::cout << "Enter columns: ";
	std::cin >> columns;
	std::cout << "Enter rows: ";
	std::cin >> rows;

	Player player = { Vector2{0,0}, 0 };
	Board board(rows, columns);
	board.initialize(
		((rows*columns) * (float)(STONE_PERCENT / (float)100)),
		((rows*columns) * (float)(COIN_PERCENT / (float)100)),
		player);

	char input = ' ';
	bool over = false;

	while (input != EXIT && !over) {
		system("CLS");
		player.print();
		board.print(player.position);

		std::cout << "\nEnter command: ";
		std::cin >> input;
		switch (input)
		{
		case 'x':
		case 'X':
			input = EXIT;
			break;
		case 'w':
		case 'W':
			input = UP;
			break;
		case 's':
		case 'S':
			input = DOWN;
			break;
		case 'a':
		case 'A':
			input = LEFT;
			break;
		case 'd':
		case 'D':
			input = RIGHT;
			break;
		default:
			input = 0;
			break;
		}

		if (board.existsCoin(player.position, (Movement)input)) {
			player.updateScore(COIN_UP);
			board.coins--;
			over = (board.coins <= 0);
		}
		player.position = board.movePlayer(player.position, (Movement)input);
	}

	std::cout << "\n\033[0;31mGAME OVER ";
	player.print();
	std::cin >> input;



}
