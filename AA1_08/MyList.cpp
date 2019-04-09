#include "MyList.h"



MyList::MyList()
{
	first = nullptr;
	last = nullptr;
}

MyList::MyList(MyList const& list_)
{
	first = nullptr;
	last = nullptr;
	NodeInt* pointer = list_.first;
	while (pointer != nullptr) {
		Push_back(pointer->value);
		pointer = pointer->next;
	}
}

//MyList::MyList(MyList const& list_)
//{
//	for (size_t i = 0; i < list_.GetNumElements(); i++)
//	{
//		Push_back(list_.GetElementPos(i));
//	}
//}

MyList::~MyList()
{
	for (size_t i = 0; i < GetNumElements(); i++)
	{
		Delete(0);
	}
}

void MyList::Push_back(int value_)
{
	NodeInt* newNode = new NodeInt(value_, last, nullptr);
	if (last != nullptr)
		last->next = newNode;
	else {
		first = newNode;
	}
	last = newNode;
}

void MyList::Pop_back()
{
	Delete(GetNumElements());
}

void MyList::Push_front(int value_)
{
	NodeInt* newNode = new NodeInt(value_, nullptr, first);
	if (first != nullptr)
		first->previous = newNode;
	else {
		last = newNode;
	}
	first = newNode;
}

void MyList::Pop_front()
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
	int i = -1;
	NodeInt* pointer = first;
	if (pointer != nullptr)
		while (i < pos_) {
			pointer = pointer->next;
			i++;
		}
	NodeInt* newNode = new NodeInt(value_, pointer, pointer->next);
	pointer->next = newNode;
	pointer->next->previous = newNode;
}

void MyList::Delete(int pos_)
{
	if (!Empty())
		if (pos_ == 0) {
			NodeInt* tempFirst = first->next;
			tempFirst->previous = nullptr;
			delete first;
			first = tempFirst;
		}
		else if (pos_ != GetNumElements()) {
			int i = -1;
			NodeInt* pointer = first;
			if (pointer != nullptr)
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
}

void MyList::DeleteAll(int value_)
{
}

void MyList::DeleteDuplicates(int value_)
{
}

void MyList::Change()
{
	int firstVal = first->value;
	first->value = last->value;
	last->value = firstVal;
}

int MyList::GetNumElements() const
{
	int i = 0;
	NodeInt* pointer = first;
	while (pointer != nullptr) {
		pointer = pointer->next;
		i++;
	}
	return i;
}

bool MyList::Empty()
{
	return GetNumElements() == 0;
}

MyList* MyList::operator=(const MyList& list_)
{
	return new MyList(list_);
}

std::ostream& operator<<(std::ostream& os, const MyList& list_)
{
	os << " < ";
	int numElements = list_.GetNumElements();
	if (numElements == 0)
	{
		os << "Empty";
	}
	else if (numElements == 1)
	{
		os << list_.GetElementPos(0);
	}
	else
	{
		for (size_t i = 0; i < numElements; i++)
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
