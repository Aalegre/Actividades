#pragma once
#include "Player.h"
#include <vector>
class PlayerContainerV
{

public:
	std::vector<Player> data;

	PlayerContainerV();
	~PlayerContainerV();
	void Add(const Player& player_);
	void print() const;
};

