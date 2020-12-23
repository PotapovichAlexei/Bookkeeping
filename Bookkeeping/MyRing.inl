#include "Exception.h"

template<typename T>
Account<T>::Account()
{

	this->size = -1;
	this->head = this->head;
	this->tail = this->tail;
	this->_login = "";
	this->_password = "";
}

template<typename T>
Account<T>::Account(Account& obj)
{
	this->head = this->head;
	this->size = -1;
	Node<T>* temp = obj.tail;

	this->_login = "";
	this->_password = "";


	for (int i = 0; i < obj._bankAcc.size(); i++)
		this->_bankAcc.push_back(obj._bankAcc[i]);

	while (temp)						//Добавление всех элементов кольца объекта в новое кольцо
	{
		pushToFront(temp->data);
		temp = temp->next;
	}

	this->head = temp;					//Начало кольца - это последний добавленный узел
	this->tail = this->head->prev;		//Конец кольца - предыдущий перед началом кольца

}

template<typename T>
Account<T>::Account(T& data)
{
	this->size = -1;
	Node<T> obj(data, this->head, this->tail);
	pushToFront(obj);

	this->_login = "";
	this->_password = "";

	this->head = this->head;					//Начало кольца - это последний добавленный узел
	this->tail = this->head->prev;		//Конец кольца - предыдущий перед началом кольца
}

template<typename T>
Account<T>::~Account()
{
	clear();
}


template<typename T>
void Account<T>::pushToFront(T& data)
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
void Account<T>::pushToBack(T& data)
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
void Account<T>::print()
{
	Node<T>* help = this->tail;
	//Iterator<T> help(this->tail);
	if (help == NULL || this->size == -1) {
		cout << "Your Ring is empty" << endl;
	}
	else {
		for (int i = 0; i < size + 1; i++) {
			cout << help->data << endl;
			help = help->next;
		}
	}
}

template<typename T>
void Account<T>::insert(T data, int index)
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
void Account<T>::deleteElement(int index)
{

	Node<T>* delNode = (*this)[index];

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
Node<T>* Account<T>::operator[](const int index)
{
	Node<T>* currNode = this->head;

	if (index >= 0 && index <= this->size) {
		for (int i = 0; i < index; ++i) currNode = currNode->next;
	}
	return currNode;
}


template<typename T>
void Account<T>::sort()
{
	Iterator<T> tmp = tail, next = tail->next;
	T chen;

	for (int i = 0; i < 2; i++) {
		tmp = tail; next = tail->next;
		do {
			if (*tmp > * next)
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
		} while (next != this->tail);
	}

}

template<typename T>
void Account<T>::find(Account<T>& newRing)
{
	T obj;
	cout << endl << "Enter information to find: ";
	cin >> obj;
	Iterator<T> it = this->tail;

	do {
		if (*it == obj)
			newRing.pushToBack(*it);
		++it;
	} while (it != this->tail);


}

template<typename T>
void Account<T>::inputRing(int index) {

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
void Account<T>::clear()
{
	if (this != NULL && this->size != -1) {
		while (this->size) deleteElement(0);
		deleteElement(0);
	}

}


template<typename T>
istream& operator>>(istream& in, Account<T>& obj)
{
	rewind(stdin);
	cout << "Login: ";
	obj._login = inputString(17);

	rewind(stdin);
	cout << "Password: ";
	obj._password = stringExceptRussian(17);
	return in;
}
template<typename T>
ostream& operator<<(ostream& out, Account<T>& obj) {
	out << "|" << setw(17) << obj._login << "|" << setw(17) << "|";
	return out;
}
template<typename T>
void Account<T>::addBankAccount()
{
	BankAccount bankAcc;
	cin >> bankAcc;
	_bankAcc.push_back(bankAcc);
}

template<typename T>
void Account<T>::printBankAccount()
{
	cout << "Your bank accounts: " << endl;
	for (int i = 0; i < this->_bankAcc.size(); i++)
		cout << this->_bankAcc[i];
}