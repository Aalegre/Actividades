#pragma once
#include <iostream>

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
	NodeInt* first;
	NodeInt* last;
public:
	MyList(); //OK
	MyList(MyList const& list_); //OK
	~MyList();

	void Push_back(int value_); //OK
	void Pop_back(); //OK
	void Push_front(int value_); //OK
	void Pop_front(); //OK
	int Front() const; //OK
	int Back() const; //OK
	int GetElementPos(int pos_) const; //OK
	int MaxElement() const const; //OK
	int MinElement() const; //OK
	void Insert(int value_, int pos_);
	void Delete(int pos_); //OK
	void DeleteAll(int value_);
	void DeleteDuplicates(int value_);
	void Change(); //OK
	int GetNumElements() const; //OK
	bool Empty(); //OK

	MyList* operator=(const MyList& list_);
	friend std::ostream& operator<<(std::ostream& os, const MyList& list_); //OK
};

