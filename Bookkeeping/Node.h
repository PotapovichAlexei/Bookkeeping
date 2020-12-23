#pragma once
#include "Header.h"
template<typename T>
class Node
{
public:
	Node* next;	//pointer to next Node
	Node* prev;	//pointer to prelast Node
	T data;		//data of Node
public:
	Node(T data, Node* next, Node* prev);	//constructor
	~Node();		//dectructor
};

//#include "Node.inl"