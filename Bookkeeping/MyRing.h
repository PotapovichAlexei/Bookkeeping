#pragma once
#include "Header.h"
#include "Node.h"
#include "Iterator.h"
#include "BankAccount.h"


template<class T>
class MyRing
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	MyRing();
	//MyRing(const MyRing& obj);					//конструктор копрования
	MyRing(T& data);
	~MyRing();

	void pushToFront(T& data);					//добавить элемент в начало кольца
	void pushToBack(T& data);					//добавить элемент в конец кольца
	void insert(T data, int index);				//вставить элемент в кольцо по указанному индексу
	void inputTransaction(int index);			//ввести элемент по индексу
		
	void deleteTransaction(int index);			//удаление элемента кольца по указанному индексу					
	void clear();								//очистить список
	
	void sort();								//Сортировка кольца по возврастанию 
	void find(MyRing<T>& NewMyRing);			//Поиск элемента кольца

	void printTransaction();					//Вывод кольца на экран
	Node<T>* operator[](const int index);		//ссылка на элемент кольца
		
	Node<T>* Begin() { return this->tail; }		//Возврат начала
	Node<T>* End() { return this->head; }		//Возврат конца

	int getSize() { return size; }				
	void setSize(int size) { this->size = size; }

	Node<T>* getHead() { return this->head; };	//Конец кольца
	Node<T>* getTail() { return this->tail; };	//Начало кольца
	//friend bool  operator==(string str1, string str2);
};

//#include "MyRing.inl"