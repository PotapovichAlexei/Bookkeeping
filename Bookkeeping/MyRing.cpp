//#include "MyRing.h"
//nclude "Exception.h"
#include "Header.h"
template<typename T>
MyRing<T>::MyRing()
{

	this->size = -1;
	this->head = this->head;
	this->tail = this->tail;

}

//template<typename T>
//MyRing<T>::MyRing(const MyRing& obj)
//{
//	this->head = this->head;
//	this->size = -1;
//	Iterator<T> temp = obj.Begin();
//	
//	//this->_acc = obj._acc;
//	if (temp) {
//		do					//Добавление всех элементов кольца объекта в новое кольцо
//		{
//			pushToFront(*temp);
//			++temp;
//		} while (temp != obj.Begin());
//
//	}
//	
//	this->head = obj.head;					//Начало кольца - это последний добавленный узел
//	this->tail = obj.tail;		//Конец кольца - предыдущий перед началом кольца
//
//}

template<typename T>
MyRing<T>::MyRing(T& data)
{
	this->size = -1;
	Node<T> obj(data, this->head, this->tail);
	pushToFront(obj);

	this->head = this->head;					//Начало кольца - это последний добавленный узел
	this->tail = this->head->prev;		//Конец кольца - предыдущий перед началом кольца
}

template<typename T>
MyRing<T>::~MyRing()
{
	//clear();
}


template<typename T>
void MyRing<T>::pushToFront(T& data)
{
	if (this->head == this->head && this->size == -1)							//Если кольцо пустое (содержит 0 элементов и указывает сам на себя)
	{
		this->head = new Node<T>(data, this->tail, this->head);
		this->tail = this->head;
		this->head->next = this->head;
		this->head->prev = this->head;
	}
	else
	{
		this->tail->prev = new Node<T>(data, this->tail, this->head);
		this->tail = this->tail->prev;

		this->head->next = this->tail;
	}

	++(this->size);
}


template<typename T>
void MyRing<T>::pushToBack(T& data)
{

	if (this->head == this->head && this->size == -1) {						//Если кольцо пустое (содержит 0 элементов и указывает сам на себя)
		this->head = new Node<T>(data, this->head, this->tail);
		this->tail = this->head;
		this->head->next = this->head;
		this->head->prev = this->head;
	}
	else {
		this->head->next = new Node<T>(data, this->tail, this->head);
		this->head = this->head->next;

		this->tail->prev = this->head;
	}

	++(this->size);
}

template<typename T>
void MyRing<T>::printTransaction()
{
	//Node<T>* help = this->tail;
	Iterator<T> help(Begin());
	if (help == NULL || getSize() == -1) {
		cout << "Empty" << endl;
	}
	else {
		for (int i = 0; i < size + 1; i++) {
			cout << help.curr->data << endl;
			++help;
		}
	}
}

template<typename T>
void MyRing<T>::insert(T data, int index)
{

	if (index == 1)
	{
		pushToFront(data);
	}
	else
	{
		Node<T>* curr = (*this)[index];
		curr->prev = new Node<T>(data, curr, curr->prev);
		curr->prev->prev->next = curr->prev;
	}
	++(this->size);
}

template<typename T>
void MyRing<T>::deleteTransaction(int index)
{

	Node<T>* delNode = (*this)[index ];

		if (delNode == this->head && delNode)											//Если это "голова" кольца
		{
			this->head = this->head->prev;
			delNode->next->prev = delNode->prev;
			delNode->prev->next = delNode->next;
			delNode->next = nullptr;
			delNode->prev = nullptr;
			delete delNode;
		}
		else if (delNode == this->tail && delNode)										//Если это "хвост" кольца
		{
			this->tail = this->tail->next;
			delNode->next->prev = delNode->prev;
			delNode->prev->next = delNode->next;
			delNode->next = nullptr;
			delNode->prev = nullptr;
			delete delNode;
		}
		else if (!(this->head == this->head && this->size == -1) && delNode)		//Если кольцо не пустое
		{

			delNode->next->prev = delNode->prev;
			delNode->prev->next = delNode->next;
			delNode->next = nullptr;
			delNode->prev = nullptr;
			delete delNode;
		}

		--(this->size);
}

template<typename T>
Node<T>* MyRing<T>::operator[](const int index)
{
	Node<T>* currNode = this->head;

	if (index >= 0 && index <= this->size) {
		for (int i = 0; i < index; ++i) currNode = currNode->next;
	}
	return currNode;
}


template<typename T>
void MyRing<T>::sort()
{
	Iterator<T> tmp = tail, next = tail->next;
	T chen;

	Iterator<T> tmp = Begin(), next = Begin();
	++next;
	T chen;

	for (int i = 0; i < this->size; i++) {
		tmp = Begin(); next = Begin(); ++next;
		do {
			if (*tmp > *next)
			{
				chen = *tmp;
				*tmp = *next;
				*next = chen;

				++tmp;
				++next;
			}
			else {
				++tmp;
				++next;
			}
		} while (next != Begin());
	}

}

template<typename T>
void MyRing<T>::find(MyRing<T>& newRing)
{
	T obj;
	cout << endl << "Enter information to find: ";
	cin >> obj;
	Iterator<T> it = Begin();

	do {
		if (*it == obj)
			newRing.pushToBack(*it);
		++it;
	} while (it != Begin());

}

template<typename T>
void MyRing<T>::inputTransaction(int index) {

	T data;
	cin >> data;

	if (index == 0)
		this->pushToFront(data);
	else if (index == this->size + 1)
		this->pushToBack(data);
	else
		this->insert(data, index);

}

template<typename T>
void MyRing<T>::clear()
{
	if (this != NULL && this->size != -1) {
		while (this->size) deleteTransaction(0);
		deleteTransaction(0);
	}
	
}

