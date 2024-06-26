#pragma once

template <typename T>
class  Node
{
public:
	T _data;
	Node<T>* next;

	void setData(T a) {
		_data = a;
	}
	T getData() {
		return _data;
	}
	void setNext(Node* n) {
		next = n;
	}
	Node* getNext() {
		return next;
	}
};
