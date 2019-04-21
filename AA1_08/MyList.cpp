#include "MyList.h"



MyList::MyList()
{
	first = nullptr;
	last = nullptr;
	numElements = 0;
}

MyList::MyList(MyList const& list_)
{
	first = nullptr;
	last = nullptr;
	NodeInt* pointer = list_.first;
	while (pointer != nullptr) {
		Push_Back(pointer->value);
		pointer = pointer->next;
	}
	numElements = list_.GetNumElements();
}

//MyList::MyList(MyList const& list_)
//{
//	for (size_t i = 0; i < list_.GetNumElements(); i++)
//	{
//		Push_Back(list_.GetElementPos(i));
//	}
//}

MyList::~MyList()
{
	Clean();
}

void MyList::Push_Back(int value_)
{
	NodeInt* newNode = new NodeInt(last, value_, nullptr);
	if (last != nullptr)
		last->next = newNode;
	else {
		first = newNode;
	}
	last = newNode;
	numElements++;
}

void MyList::Pop_Back()
{
	Delete(numElements - 1);
}

void MyList::Push_Front(int value_)
{
	NodeInt* newNode = new NodeInt(nullptr, value_, first);
	if (first != nullptr)
		first->previous = newNode;
	else {
		last = newNode;
	}
	first = newNode;
	numElements++;
}

void MyList::Pop_Front()
{
	Delete(0);
}

int MyList::Front() const
{
	return first->value;
}

int MyList::Back() const
{
	return last->value;
}

int MyList::GetElementPos(int pos_) const
{
	int i = -1;
	int value = 0;
	NodeInt* pointer = first;
	if(pointer != nullptr)
		while (i < pos_) {
			value = pointer->value;
			pointer = pointer->next;
			i++;
		}
	return value;
}

int MyList::MaxElement() const
{
	int value = INT_MIN;
	NodeInt* pointer = first;
	while (pointer != nullptr) {
		if (pointer->value > value)
			value = pointer->value;
		pointer = pointer->next;
	}
	return value;
}

int MyList::MinElement() const
{
	int value = INT_MAX;
	NodeInt* pointer = first;
	while (pointer != nullptr) {
		if (pointer->value < value)
			value = pointer->value;
		pointer = pointer->next;
	}
	return value;
}

void MyList::Insert(int value_, int pos_)
{
	if (numElements > 0) {
		if (pos_ == 0) {
			Push_Front(value_);
		}
		else if (pos_ == numElements) {
			Push_Back(value_);
		}
		else {
			int i = 0;
			NodeInt* pointer = first;
			while (i < pos_) {
				if (pointer->next == nullptr)
					Push_Back(0);
				pointer = pointer->next;
				i++;
			}
			NodeInt* newNode = new NodeInt(pointer->previous, value_, pointer);
			pointer->previous->next = newNode;
			pointer->previous = newNode;
			numElements++;
		}
	}
	else {
		int i = 0;
		while (i < pos_) {
			Push_Back(0);
			i++;
		}
		Push_Back(value_);
	}
}

void MyList::Delete(int pos_)
{
	if (numElements > 1) {
		if (pos_ == 0) {
			NodeInt* tempFirst = first->next;
			tempFirst->previous = nullptr;
			delete first;
			first = tempFirst;
		}
		else if (pos_ != numElements - 1) {
			int i = -1;
			NodeInt* pointer = first;
			while (i < pos_) {
				pointer = pointer->next;
				i++;
			}
			pointer->previous->next = pointer->next;
			pointer->next->previous = pointer->previous;
			delete pointer;
		}
		else {
			NodeInt* tempLast = last->previous;
			tempLast->next = nullptr;
			delete last;
			last = tempLast;
		}
		numElements--;
	}
	else if (numElements == 1) {
		delete first;
		first = nullptr;
		last = nullptr;
		numElements--;
	}
}

void MyList::DeleteAll(int value_)
{
	if (numElements > 0) {
		if (numElements > 1) {
			int i = 0;
			NodeInt* pointer = first;
			while (pointer != nullptr) {
				if (pointer->value == value_) {
					NodeInt* nextPointer = pointer->next;
					if (i == 0 || i == numElements) {
						Delete(i);
					}
					else {
						pointer->previous->next = nextPointer;
						nextPointer->previous = pointer->previous;
						delete pointer;
						numElements--;
					}
					pointer = nextPointer;
					i--;
				}
				else {
					pointer = pointer->next;
				}
				i++;
			}
		}
		else {
			if (first->value == value_)
				Delete(0);
		}
	}
}

void MyList::DeleteDuplicates()
{
	if (numElements > 0) {
		NodeInt* pointer = last;
		int i = numElements - 1;
		MyList tempList;
		while (pointer != nullptr) {
			if (!tempList.Contains(pointer->value)) {
				tempList.Push_Back(pointer->value);
			}
			i--;
			pointer = pointer->previous;
		}
		Clean();
		pointer = tempList.first;
		while (pointer != nullptr) {
			Push_Front(pointer->value);
			pointer = pointer->next;
		}
		tempList.Clean();
	}
}

void MyList::Change()
{
	int firstVal = first->value;
	first->value = last->value;
	last->value = firstVal;
}

int MyList::GetNumElements() const
{
	return numElements;
}
//int MyList::GetNumElements() const
//{
//	int i = 0;
//	NodeInt* pointer = first;
//	while (pointer != nullptr) {
//		pointer = pointer->next;
//		i++;
//	}
//	return i;
//}

bool MyList::Empty()
{
	return numElements == 0;
}

void MyList::Print()
{
	std::cout << " < ";
	if (numElements == 0)
	{
		std::cout << "Empty";
	}
	else if (numElements == 1)
	{
		std::cout << GetElementPos(0);
	}
	else
	{
		for (size_t i = 0; i < numElements; i++)
		{
			if (i == 0)
				std::cout << GetElementPos(i);
			else
				std::cout << ", " << GetElementPos(i);
		}
	}
	std::cout << " > ";
}

bool MyList::Contains(int value_)
{
	if (numElements > 0) {
		NodeInt* pointer = first;
		while (pointer != nullptr) {
			if (pointer->value == value_)
				return true;
			pointer = pointer->next;
		}
	}
	return false;
}

void MyList::Clean()
{
	if (numElements > 0)
		while (numElements > 0)
			Delete(0);
}


bool operator==(const MyList& list1_, const MyList& list2_)
{
	if (list1_.numElements != list2_.numElements) {
		return false;
	}
	MyList::NodeInt* pointer1 = list1_.first;
	MyList::NodeInt* pointer2 = list2_.first;
	while (pointer1 != nullptr && pointer2 != nullptr) {
		if (pointer1->value != pointer2->value)
			return false;
		pointer1 = pointer1->next;
		pointer2 = pointer2->next;
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const MyList& list_)
{
	os << " < ";
	if (list_.numElements == 0)
	{
		os << "Empty";
	}
	else if (list_.numElements == 1)
	{
		os << list_.GetElementPos(0);
	}
	else
	{
		for (size_t i = 0; i < list_.numElements; i++)
		{
			if (i == 0)
				os << list_.GetElementPos(i);
			else
				os << ", " << list_.GetElementPos(i);
		}
	}
	os << " > ";
	return os;
}
