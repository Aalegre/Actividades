#include "PlayerContainerV.h"

int main() {

	PlayerContainerV players1;
	players1.Add({ 100, "Jofrillos" });
	players1.Add({ 100, "Paralelepipedo" });
	players1.Add({ 234, "Albaricoque" });
	players1.Add({ 2, "Sabrinb" });
	players1.Add({ 2, "Sabrina" });
	players1.Add({ 500, "Z" });
	players1.Add({ 500, "A" });
	players1.Add({ 500, "a" });
	players1.Add({ 500, "b" });
	players1.Add({ 500, "a" });
	int playerScore = 0;
	std::string playerName = "";
	std::cout << "Introduzca un nombre: ";
	std::cin >> playerName;
	std::cout << std::endl << "Introduzca una puntuacion: ";
	std::cin >> playerScore;
	std::cout << std::endl;
	players1.Add({ playerScore, playerName });
	players1.print();

	return 0;
}