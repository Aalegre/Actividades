#pragma once
struct Player {
	int posI;
	int posJ;
	int score;

	void updateScore() {
		score++;
	}
};