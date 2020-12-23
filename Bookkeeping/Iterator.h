#pragma once
#include "Node.h"
#include "Header.h"
template<typename T>
class Iterator {

public:
	Node<T>* curr;

public:
	Iterator(Node<T>* current = nullptr);

	void operator++ (void);	//Следующий узел
	void operator-- ();		//Предыдущий узел
	void operator= (T data);//Присвоить данные
	void operator = (Node<T>* tmp);//Присвоить указатель на узел
	T& operator*(void);				//Возврат данных
	bool operator==(Node<T>* tmp);	//Оператор сравнения
	bool operator!=(Node<T>* tmp);	//Оператор не ровно	
	bool operator!=(Iterator<T> tmp);//
	void operator+=(const int& tmp);// Перескочить на N позиций
};

//#include "Iterator.inl"