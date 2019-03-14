#include <iostream>
#include <vector>

void main() {
	std::vector<int> v1(5);
	std::vector<int> v2(10, 0);
	std::vector<int> v3 = { 10,9,8,7,6,5,4,3,2,1 };
	std::vector<std::string> v4 = { "Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia" };
	std::vector<int> v5(v3);
	std::vector<int> v6(v3);

}