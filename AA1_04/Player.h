#pragma once
struct Player {
	Vector2 position;
	int score;

	void updateScore() { score++; }
	void updateScore(int points) { score += points; }

	void setPos(Vector2 newPosition) { position = newPosition; }

	void print(){
		std::cout << "\033[0;33mScore:   " << score << "\033[0;0m";
	}
};