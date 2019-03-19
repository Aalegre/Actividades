#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Types.h"

std::vector<int> addVectors(std::vector<int> v1_, std::vector<int> v2_) { //V2 EL MÁS ÓPTIMO
	if (v1_.size() > v2_.size()) {
		std::vector<int> result(v1_);
		for (int i = 0; i < v2_.size(); i++)
		{
			result[i] += v2_[i];
		}
		return result;
	}
	else {
		std::vector<int> result(v2_);
		for (int i = 0; i < v1_.size(); i++)
		{
			result[i] += v1_[i];
		}
		return result;
	}
}
std::vector<int> addVectorsv3(std::vector<int> v1_, std::vector<int> v2_) { //V3
	std::vector<int> result(v1_);
	for (int i = 0; i < v2_.size(); i++)
	{
		if (i < v1_.size())
			result[i] += v2_[i];
		else
			result.push_back(v2_[i]);
	}
}
std::vector<int> addVectorsv1(std::vector<int> v1_, std::vector<int> v2_) { //V1
	if (v1_.size() > v2_.size()) {
		std::vector<int> result(v1_.size());
		for (int i = 0; i < v1_.size(); i++)
		{
			if(i >= v2_.size())
				result[i] = v1_[i];
			else
				result[i] = v1_[i] + v2_[i];
		}
		return result;
	}
	else {
		std::vector<int> result(v2_.size());
		for (int i = 0; i < v2_.size(); i++)
		{
			if (i >= v1_.size())
				result[i] = v2_[i];
			else
				result[i] = v2_[i] + v1_[i];
		}
		return result;
	}
}
std::vector<int> addVectorsv1(std::vector<int> v1_, std::vector<int> v2_) { //V1
	if (v1_.size() > v2_.size()) {
		std::vector<int> result(v1_.size());
		for (int i = 0; i < v1_.size(); i++)
		{
			if(i >= v2_.size())
				result[i] = v1_[i];
			else
				result[i] = v1_[i] + v2_[i];
		}
		return result;
	}
	else {
		std::vector<int> result(v2_.size());
		for (int i = 0; i < v2_.size(); i++)
		{
			if (i >= v1_.size())
				result[i] = v2_[i];
			else
				result[i] = v2_[i] + v1_[i];
		}
		return result;
	}
}

void concatVectors(std::vector<std::string> &v1_, std::vector<std::string> v2_) {
	for (int i = 0; i < v2_.size(); i++)
	{
		v1_.push_back(v2_[i]);
	}
}

void shiftRight(std::vector<int> &v_) {
	v_.insert(v_.begin(), rand() % 101);
	v_.pop_back();
}

void rotateLeft(std::vector<int> &v_) {
	v_.push_back(v_[0]);
	v_.erase(v_.begin());
}

void searchAdjacent(std::vector<int> &v_) {
	if (v_.size() > 2) {
		for (int i = 0; i < v_.size() - 2; i++)
		{
			if (v_[i] == v_[i+1] && v_[i+1] == v_[i+2]) {
				v_[i] = rand() % 101;
				v_[i + 1] = rand() % 101;
				v_[i + 2] = rand() % 101;
			}
		}
	}
}

bool isPalindrome(std::vector<char> &v_) {
	std::vector<char> vTemp(v_);
	std::reverse(vTemp.begin(), vTemp.end());
	return (v_ == vTemp);
}

void print(std::vector<int> &v_) {
	std::cout << "\nArray filled:	" << v_.size() << "/" << v_.capacity() << "\n";
	for (int i = 0; i < v_.size(); i++) {
		std::cout << "Element: " << i << "	> " << v_[i] << "\n";
	}
	if (v_.size() < v_.capacity()) {
		std::cout << "Still left	" << v_.capacity() - v_.size() << " empty spaces\n\n";
	}
	else {
		std::cout << "No empty spaces left\n\n";
	}
}
void print(std::vector<std::string> &v_) {
	std::cout << "\nArray filled:	" << v_.size() << "/" << v_.capacity() << "\n";
	for (int i = 0; i < v_.size(); i++) {
		std::cout << "Element: " << i << "	> " << v_[i] << "\n";
	}
	if (v_.size() < v_.capacity()) {
		std::cout << "Still left	" << v_.capacity() - v_.size() << " empty spaces\n\n";
	}
	else {
		std::cout << "No empty spaces left\n\n";
	}
}

void main() {
	//Uso de las funciones del ejercicio 2

	//A con vectores del mismo tamaño
	std::vector<int> v11({ 10,20,30 });
	std::vector<int> v12(v11);
	std::vector<int> v13 = addVectors(v11, v12);

	std::cout << "A(20-40-60):";
	print(v13);

	//A con vectores de diferente tamaño
	std::vector<int> v21({ 10,20,30 });
	std::vector<int> v22({ 10,20,30,40,50 });
	std::vector<int> v23 = addVectors(v21, v22);

	std::cout << "A(20-40-60,40,50):";
	print(v23);

	//B 
	std::vector<std::string> vb1({ "dabale" ,"arroz","a","la","zorra" });
	std::vector<std::string> vb2({ "el","abad" });
	concatVectors(vb1, vb2);

	std::cout << "B(dabalearrozalazorraelabad):";
	print(vb1);

	//C
	shiftRight(v21);

	std::cout << "C(X,10,20):";
	print(v21);

	//D
	rotateLeft(v22);
	std::cout << "D(20,30,40,50,10):";
	print(v22);

	//E
	std::vector<int>ve1({ 1,2,2,2,3,4,5 });
	searchAdjacent(ve1);
	std::cout << "E(1,X,X,X,3,4,5):";
	print(ve1);


	std::vector<int>ve2({ 1,2,2,3,4,5 });
	searchAdjacent(ve2);
	std::cout << "E(1,2,2,3,4,5):";
	print(ve2);

	std::vector<int>ve3({ 1,2,2,3,4,5,5,5 });
	searchAdjacent(ve3);
	std::cout << "E(1,2,2,3,4,X,X,X):";
	print(ve3);

	//F
	std::vector<std::string> fraseS({ "dabale" ,"arroz","a","la","zorra","el","abad" });
	std::vector<char> fraseC({ 'd','a','b','a','l','e',' ' ,'a','r','r','o','z',' ' ,'a',' ' ,'l','a',' ' ,'z','o','r','r','a',' ' ,'e' ,'l',' ' ,'a','b','a','d' });



	std::cout << "Introduzca un valor para salir...";
	char exit;
	std::cin >> exit;
}

void mainPropio() {
	srand(time(NULL));
	std::vector<int> v1(5);
	std::vector<int> v2(10, 0	);
	std::vector<int> v3 = { 10,9,8,7,6,5,4,3,2,1 };
	std::vector<std::string> v4 = { "Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia" };
	std::vector<int> v5(v3);
	std::vector<Persona> v6(3);

	std::cout << "Introduzca un valor para salir...";
	char exit;
	std::cin >> exit;
}
