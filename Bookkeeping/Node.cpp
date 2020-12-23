//#include "Node.h"
//#include "Exception.h"
#include "Header.h"
template<typename T>
Node<T> ::Node(T data, Node* next, Node* prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}

template<typename T>
Node<T>::~Node()
{
	delete this->next;
	delete this->prev;
}

