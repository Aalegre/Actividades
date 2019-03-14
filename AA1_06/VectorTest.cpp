#include <iostream>
#include <vector>
#include <ctime>
#include "Types.h"

std::vector<int> addVectors(std::vector<int> v1_, std::vector<int> v2_) {
	std::vector<int> result(v1_.size());
	if (v1_.size() == v2_.size()) {
		for (int i = 0; i < v1_.size(); i++)
		{
			result[i] = v1_[i] + v2_[i];
		}
	}
	return result;
}
void concatVectors(std::vector<std::string> &v1_, std::vector<std::string> v2_) {
	for (int i = 0; i < v2_.size(); i++)
	{
		v1_.push_back(v2_[i]);
	}
}

void shiftRight(std::vector<int> &v_) {
	v_.insert(v_.begin(), rand() % 101);
}

void rotateLeft(std::vector<int> &v_) {
	int firstVal = v_[0];
	v_.erase(v_.begin());
	v_.push_back(firstVal);
}

void searchAdjacent(std::vector<int> &v_) {

}

bool isPalindrome(std::vector<char> &v_) {
	std::vector<char> vTemp(v_);
	std::reverse(vTemp.begin(), vTemp.end());
	return (v_ == vTemp);
}

void main() {
	srand(time(NULL));
	std::vector<int> v1(5);
	std::vector<int> v2(10, 0);
	std::vector<int> v3 = { 10,9,8,7,6,5,4,3,2,1 };
	std::vector<std::string> v4 = { "Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia" };
	std::vector<int> v5(v3);
	std::vector<Persona> v6(3);
	//std::string v7s = "dabalearrozalazorraelabad";
	//std::vector<char> v7(v7s.begin(), v7s.end());
	//bool v7pal = isPalindrome(v7);
	for (int i = 0; i < v6.size(); i++)
	{
		v6[i] = Persona(v4[rand() % v4.size()], rand() % 89999999 + 10000000, Date(rand() % 30 + 1, rand() % 11 + 1, rand() % 100 + 1919));
	}
	std::cout << "Introduzca un valor para salir...";
	char exit;
	std::cin >> exit;
}
