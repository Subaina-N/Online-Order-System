#include "GList.h"

template <typename T>
GList<T>::GList()
{
	root = NULL;
	noe = 0;
}

template <typename T>
GList<T>::~GList()
{
	Node<T>* current = root;
	while (current)
	{
		Node<T>* next = current->next;
		delete current;
		current = next;
	}
	root = NULL;
}

template <typename T>
bool GList<T>::isEmpty()
{
	if (!root)
		return true;
	else
		return false;
}

template <typename T>
void GList<T>::Insert(T* _data)
{
	Node<T>* newNode = new Node<T>();
	newNode->_data = *_data;
	newNode->next = NULL;
	if (isEmpty())
	{
		root = newNode;
	}
	else
	{
		Node<T>* current = root;
		while (current->next)
			current = current->next;
		current->next = newNode;
	}
	noe++;
}

template <typename T>
void GList<T>::Delete(T* _data)
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		Node<T>* current = root;
		Node<T>* prev = NULL;

		while (current && current->_data != *_data)
		{
			prev = current;
			current = current->next;
		}
		if (!current)
		{
			cout << "Not Found\n";
			return;
		}
		if (!prev)
		{
			root = root->next;
		}
		else
		{
			prev->next = current->next;
		}

		delete current;
	}
	noe--;
}



template <typename T>
void GList<T>::Print()
{
	if (isEmpty())
	{
		cout << "Empty GList\n";
	}
	else
	{
		Node<T>* temp;

		temp = root;

		for (int i = 0; temp; i++)
		{
			cout << "\t\t\t\t" << i + 1 << ". " << temp->_data << endl;
			temp = temp->next;
		}
	}
}

template <typename T>
Node<T>* GList<T>::Get(int index)
{
	if (0)
	{
		return root;
	}
	else
	{
		Node<T>* temp = root;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}
}

template <typename T>
bool GList<T>::operator == (GList temp)
{
	if (root == temp.root)
		return true;
	else
		return false;
}

template <typename T>
bool GList<T>::operator != (GList temp)
{
	if (root == temp.root)
		return false;
	else
		return true;
}