/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#include "List.h"
#include <cassert>
#include <string>

template<class ItemType>
List<ItemType>::List() : headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
List<ItemType>::List(const List<ItemType>& aList)
{
	itemCount = aList.itemCount;
	Node<ItemType>* origChainPtr = aList.headPtr;
	if (origChainPtr == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		//copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		//copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;
		while ((origChainPtr->getNext()) != nullptr)
		{
			origChainPtr = origChainPtr->getNext();
			//get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
			//create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			//link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			//advance pointer to new last node
			newChainPtr = newChainPtr->getNext();
		}
		newChainPtr->setNext(nullptr);
	}
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		std::string message = "getEntry() called with an empty list or invalid position";
		throw(PrecondViolatedExcept(message));
	}
}

template<class ItemType>
void List<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
{
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
	else
	{
		std::string message = "setEntry() called with an empty list or invalid position";
		throw(PrecondViolatedExcept(message));
	}
}

template<class ItemType>
Node<ItemType>* List<ItemType>::getNodeAt(int position) const
{
	assert((position >= 1) && (position <= itemCount));
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();
	return curPtr;
}

template< class ItemType>
bool List<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) &&
		(newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		if (newPosition == 1)
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;
	}
	return ableToInsert;
}

template< class ItemType>
bool List<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--;
	}
	return ableToRemove;
}

template< class ItemType>
void List<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}

template< class ItemType>
List<ItemType>::~List()
{
	clear();
}

template< class ItemType>
bool List<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template< class ItemType>
int List<ItemType>::getLength() const
{
	return itemCount;
}