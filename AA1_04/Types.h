#pragma once

enum Movement {
	//UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', EXIT = 'x',
	UP = 'W', DOWN = 'S', LEFT = 'A', RIGHT = 'D', EXIT = 'X'
};
enum Items { PATH = '.', STONE = '#', COIN = '$', PLAYER = '@' };
struct Vector2
{
	int i;
	int j;
	Vector2(int i_, int j_) {
		i = i_;
		j = j_;
	}
};