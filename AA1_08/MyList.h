#pragma once
class MyList
{
	struct NodeInt {
		int value;
		NodeInt* previous;
		NodeInt* next;
		NodeInt() {};
		NodeInt(int value_) { value = value_; previous = nullptr; next = nullptr; };
		NodeInt(int value_, NodeInt* previous_, NodeInt* next_) { value = value_; previous = previous_; next = next_; };
	};
public:
	MyList();
	~MyList();
};

