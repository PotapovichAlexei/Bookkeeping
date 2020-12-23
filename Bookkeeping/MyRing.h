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
	//MyRing(const MyRing& obj);					//����������� ����������
	MyRing(T& data);
	~MyRing();

	void pushToFront(T& data);					//�������� ������� � ������ ������
	void pushToBack(T& data);					//�������� ������� � ����� ������
	void insert(T data, int index);				//�������� ������� � ������ �� ���������� �������
	void inputTransaction(int index);			//������ ������� �� �������
		
	void deleteTransaction(int index);			//�������� �������� ������ �� ���������� �������					
	void clear();								//�������� ������
	
	void sort();								//���������� ������ �� ������������ 
	void find(MyRing<T>& NewMyRing);			//����� �������� ������

	void printTransaction();					//����� ������ �� �����
	Node<T>* operator[](const int index);		//������ �� ������� ������
		
	Node<T>* Begin() { return this->tail; }		//������� ������
	Node<T>* End() { return this->head; }		//������� �����

	int getSize() { return size; }				
	void setSize(int size) { this->size = size; }

	Node<T>* getHead() { return this->head; };	//����� ������
	Node<T>* getTail() { return this->tail; };	//������ ������
	//friend bool  operator==(string str1, string str2);
};

//#include "MyRing.inl"