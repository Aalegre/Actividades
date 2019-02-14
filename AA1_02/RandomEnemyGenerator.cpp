#include <iostream>
#include <string>
#include <ctime>

//Problem 1
enum EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH };
std::string enemyTypes[4]{ "ZOMBIE", "VAMPIRE", "GHOST", "WITCH" };

std::string names[10] = { "Sabrina" , "Zelda" , "Hilda" , "Django" , "Patroclo" , "Schubert" , "John" , "Lesbos" , "Eucrecia" , "Brumbhilda" };

const int MAX_ENEMIES = 5;

//Problem 2
struct Enemy {
	EnemyType type;
	std::string name;
	int health;

	Enemy(){}
	Enemy(EnemyType _type, std::string _name, int _health) {
		type = _type;
		name = _name;
		health = _health;
	}
};

//Problem 3
bool equalEnemies(Enemy enemy1, Enemy enemy2) {
	return (enemy1.type == enemy2.type && enemy1.name == enemy2.name);
}

//Problem 4
Enemy createRandomEnemy() {
	return Enemy(EnemyType(rand() % 4), names[rand() % 10], 50 + (rand() % 51));
}


//Problem 5
std::string getEnemyTypeString(EnemyType enemyType) {
	return enemyTypes[enemyType];
}

int main() {
	time_t t;
	srand((unsigned)time(&t));

	//Problem 6
	 Enemy enemies[MAX_ENEMIES];

	//Problem 7
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		Enemy enemy = createRandomEnemy();
		for (int j = i; j >= 0; j--)
		{
			if (equalEnemies(enemy, enemies[j])) {
				enemy = createRandomEnemy();
				j = i;
			}
		}
		enemies[i] = enemy;
	}
}