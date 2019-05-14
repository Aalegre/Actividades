#pragma once
#include <iostream>
#include <iterator>
#include <string>
class Player
{
	int score = 0;
	std::string name = "";
public:
	Player();
	Player(int score_, std::string name_);
	~Player();

	bool operator<(const Player& p_) const;
	bool operator>(const Player& p_) const;

	int GetScore() const;

	std::string GetName() const;
};

