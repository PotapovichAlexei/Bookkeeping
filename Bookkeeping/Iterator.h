#pragma once
#include "Node.h"
#include "Header.h"
template<typename T>
class Iterator {

public:
	Node<T>* curr;

public:
	Iterator(Node<T>* current = nullptr);

	void operator++ (void);	//��������� ����
	void operator-- ();		//���������� ����
	void operator= (T data);//��������� ������
	void operator = (Node<T>* tmp);//��������� ��������� �� ����
	T& operator*(void);				//������� ������
	bool operator==(Node<T>* tmp);	//�������� ���������
	bool operator!=(Node<T>* tmp);	//�������� �� �����	
	bool operator!=(Iterator<T> tmp);//
	void operator+=(const int& tmp);// ����������� �� N �������
};

//#include "Iterator.inl"