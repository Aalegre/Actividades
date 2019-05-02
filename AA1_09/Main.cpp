
#include <iostream>
#include <iterator>
#include <deque>
#include <stack>
#include <string>

struct person
{
	std::string name; int age;
	int Person() { name = "Alex"; age = 20;	}
	int Person(std::string name_, int age_) {name = name_;age = age_;}

	bool operator<(const person& p_) const {
		return (age < p_.age);
	}
	bool operator==(const person& p_) const {
		return (age == p_.age);
	}
};

std::deque<int> superMerge(std::deque<int>& d1_, std::deque<int>& d2_) {
	std::deque<int> temp;

	if (!d1_.empty() && !d2_.empty()) {
		std::deque<int>::iterator it1 = d1_.begin();
		std::deque<int>::iterator it2 = d2_.begin();
		while (it1 != d1_.end() || it2 != d2_.end()) {
			int value1;
			int value2;

			if (it1 == d1_.end()) value1 = INT16_MAX; else value1 = *it1;
			if (it2 == d2_.end()) value2 = INT16_MAX; else value2 = *it2;

			if (value1 < value2) {
				temp.push_back(value1);
				if (it1 != d1_.end()) {
					it1++;
				}
			}
			else {
				temp.push_back(value2);
				if (it2 != d2_.end()) {
					it2++;
				}
			}
		}
	}


	return temp;
}

void printReverse(std::deque<int>& d_) {
	if (!d_.empty()) {
		std::deque<int>::iterator it = d_.end() - 1;
		while (it != d_.begin()) {
			std::cout << *it << ' ';
			it--;
		}
		std::cout << *d_.begin() << std::endl;
	}
}

bool isBalanced(std::deque<char>& d_) {
	int sumador = 0;
	if (!d_.empty()) {
		std::deque<char>::iterator it = d_.begin();
		while (it != d_.end()) {
			if (*it == ')')
				sumador++;
			else if (*it == '(')
				sumador--;
			it++;
		}
	}
	return sumador == 0;
}


std::deque<int> concat(std::deque<int>& d1_, std::deque<int>& d2_) {
	std::deque<int> temp;

	if (!d1_.empty() && !d2_.empty()) {
		std::deque<int>::iterator it = d1_.begin();
		while (it != d1_.end()) {
			temp.push_back(*it);
			it++;
		}
		it = d2_.begin();
		while (it != d2_.end()) {
			temp.push_back(*it);
			it++;
		}
	}
	return temp;
}

bool operator<(const std::deque<int>& d1_, const std::deque<int>& d2_) {
	return (d1_.size() < d2_.size());
}

bool operator<(const std::stack<person>& s1_, const std::stack<person>& s2_) {
	return (s1_.top() < s2_.top());
}

bool operator==(const std::deque<int>& d1_, const std::deque<int>& d2_) {
	return (d1_.size() == d2_.size());
}

bool operator==(const std::stack<person>& s1_, const std::stack<person>& s2_) {
	return (s1_.top() == s2_.top());
}

int main() {

	std::deque<int> d1({ 1,2,3,4,5,6,7,80,90,100 });
	std::deque<int> d2({ 9,10,11,12,13 });
	std::deque<int> d3 = superMerge(d1, d2);

	printReverse(d3);


	std::deque<char> d4({ '(',')','(','(','(',')',')','(' });
	bool balanced = isBalanced(d4);

	std::deque<int> d5 = concat(d3, d2);


	bool minusInt = (d2 < d1);
	bool equalInt = (d2 == d1);

	std::stack<person> s1;
	s1.push({ "patata", 10 });
	s1.push({ "arga", 104 });
	s1.push({ "awfe", 120 });
	s1.push({ "gaer", 19 });

	std::stack<person> s2;

	s2.push({ "awef", 90 });
	s2.push({ "sss", 104 });
	s2.push({ "eeee", 120 });
	s2.push({ "iiii", 19 });


	bool minusPerson = (s2 < s1);
	bool equalPerson = (s2 == s1);


	return 0;
}