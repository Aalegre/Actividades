#include <iostream>
#include <string>
#include <ctime>

//Problem 1
enum class EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH, COUNT };
std::string enemyTypes[]{ "ZOMBIE", "VAMPIRE", "GHOST", "WITCH" };

const std::string NAMES[] = { "Sabrina" , "Zelda" , "Hilda" , "Django" , "Patroclo" , "Schubert" , "John" , "Lesbos" , "Eucrecia" , "Brumbhilda" };

const int MAX_ENEMIES = 5;

//Problem 2
struct Enemy {
	EnemyType type;
	std::string name;
	int health;

	Enemy() {}
	Enemy(EnemyType type_, std::string name_, int health_) {
		type = type_;
		name = name_;
		health = health_;
	}
};

//Problem 3
bool equalEnemies(Enemy enemy1_, Enemy enemy2_) {
	return enemy1_.type == enemy2_.type && enemy1_.name == enemy2_.name;
}
//Problem 3 Sobrecarga de operador ==
bool operator==(const Enemy &a, const Enemy &b) {
	return a.type == b.type && a.name == b.name;
}

//Problem 4
Enemy createRandomEnemyConstructor() { //un poco más lento
	return Enemy(
		EnemyType(rand() % 4), 
		NAMES[rand() % 10], 
		50 + (rand() % 51));
}
Enemy createRandomEnemy() {
	return Enemy{ 
		EnemyType(rand() % 4), 
		NAMES[rand() % (sizeof(NAMES)/sizeof(NAMES[0]))], 
		50 + (rand() % 51) };
}



//Problem 5
std::string getEnemyTypeString(EnemyType enemyType_) {
	switch (enemyType_) {
	case EnemyType::ZOMBIE: return "ZOMBIE";
	case EnemyType::VAMPIRE: return "VAMPIRE";
	case EnemyType::GHOST: return "GHOST";
	case EnemyType::WITCH: return "WITCH";
	default: return "";
	}
}

int main() {
	time_t t;
	srand((unsigned)time(&t));

	//Problem 6
	Enemy enemies[MAX_ENEMIES];

	//Problem 7
	int i = 0;
	while (i < MAX_ENEMIES) {
		enemies[i] = createRandomEnemy();
		int j = i - 1;
		while (j >= 0) {
			if (enemies[i] == enemies[j]) { --i; break; };
			--j;
		};
		i++;
	}

	std::cout << "    List of enemies:\n\n";

	for (Enemy e : enemies)
	{
		std::cout << e.name << " is a " << getEnemyTypeString(e.type) << " with power " << e.health << "\n";
	}


	return 0;
}