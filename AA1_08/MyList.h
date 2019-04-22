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
		//NodeInt(int value_, NodeInt* previous_, NodeInt* next_) { value = value_; previous = previous_; next = next_; };
		NodeInt(NodeInt* previous_, int value_, NodeInt* next_) { previous = previous_; value = value_; next = next_; };
	};
	NodeInt* first;
	NodeInt* last;
	unsigned int numElements;
public:
	MyList();
	MyList(MyList const& list_);
	~MyList();

	void Push_Back(int value_);
	void Pop_Back();
	void Push_Front(int value_);
	void Pop_Front();
	int Front() const;
	int Back() const;
	int GetElementPos(int pos_) const;
	int MaxElement() const;
	int MinElement() const;
	void Insert(int value_, int pos_);
	void Delete(int pos_);
	void DeleteAll(int value_);
	void DeleteDuplicates();
	void Change();
	int GetNumElements() const;
	bool Empty();

	//Extras
	void Print();
	void PrintReverse();
	bool Contains(int value_);
	void Clean();

	friend bool operator==(const MyList& list1_, const MyList& list2_);
	friend std::ostream& operator<<(std::ostream& os, const MyList& list_);
};

