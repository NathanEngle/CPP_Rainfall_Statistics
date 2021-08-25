/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#pragma once

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template <class ItemType>
class List : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	Node<ItemType>* getNodeAt(int position) const;
public:
	List();
	List(const List<ItemType>& aList);
	virtual ~List();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	void setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);
};

#include "List.cpp"