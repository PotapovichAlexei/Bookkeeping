template<typename T>
Node<T> ::Node(T data, Node* next, Node* prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}

template<typename T>
void Node<T>::swap(T& data)
{
	T temp;
	temp = data;
	data = this->data;
	this->data = temp;
}

template<typename T>
Node<T>::~Node()
{
	delete this->next;
	delete this->prev;
}

