//#include <iostream>
//#include <string>
//#include <ctime>
//
////Problem 1
//enum EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH };
//std::string enemyTypes[4]{ "ZOMBIE", "VAMPIRE", "GHOST", "WITCH" };
//
//std::string names[10] = { "Sabrina" , "Zelda" , "Hilda" , "Django" , "Patroclo" , "Schubert" , "John" , "Lesbos" , "Eucrecia" , "Brumbhilda" };
//
//const int MAX_ENEMIES = 5;
//
////Problem 2
//struct Enemy {
//	EnemyType type;
//	std::string name;
//	int health;
//
//	Enemy(){}
//	Enemy(EnemyType type_, std::string name_, int health_) {
//		type = type_;
//		name = name_;
//		health = health_;
//	}
//};
//
////Problem 3
//bool equalEnemies(Enemy enemy1_, Enemy enemy2_) {
//	return (enemy1_.type == enemy2_.type && enemy1_.name == enemy2_.name);
//}
//
////Problem 4
//Enemy createRandomEnemy() {
//	return Enemy(EnemyType(rand() % 4), names[rand() % 10], 50 + (rand() % 51));
//}
//
//
////Problem 5
//std::string getEnemyTypeString(EnemyType enemyType_) {
//	return enemyTypes[enemyType_];
//}
//
//int mainOld() {
//	time_t t;
//	srand((unsigned)time(&t));
//
//	//Problem 6
//	 Enemy enemies[MAX_ENEMIES];
//
//	//Problem 7
//	for (int i = 0; i < MAX_ENEMIES; i++)
//	{
//		Enemy enemy = createRandomEnemy();
//		for (int j = i; j >= 0; j--)
//		{
//			if (equalEnemies(enemy, enemies[j])) {
//				enemy = createRandomEnemy();
//				j = i;
//			}
//		}
//		enemies[i] = enemy;
//	}
//	return 0;
//}