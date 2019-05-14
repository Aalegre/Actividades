#include "PlayerContainerV.h"



PlayerContainerV::PlayerContainerV()
{
}


PlayerContainerV::~PlayerContainerV()
{
}

void PlayerContainerV::Add(const Player& player_)
{
	if (data.size() > 0) {
		size_t i = 0;
		while (i < data.size() && player_ < data[i]) {
			i++;
		}
		if (i >= data.size()) {
			data.push_back(player_);
		}
		else {
			data.insert(data.begin() + i, player_);
		}
	}
	else {
		data.push_back(player_);
	}
}

void PlayerContainerV::print() const
{
	std::cout << "Player list: " <<  std::endl;
	for (Player p : data)
	{
		std::cout << " - " << p.GetScore() << '	' << p.GetName() << std::endl;
	}
}
