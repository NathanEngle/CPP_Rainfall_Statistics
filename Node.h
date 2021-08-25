/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#pragma once
template<class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* next;
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};
#include "Node.cpp"