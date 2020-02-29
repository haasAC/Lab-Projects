#pragma once
#include"sequence.h"
#include <iostream>
#include <cstdio>
using namespace std;

template <class T>
Sequence<T>::Sequence()
{
	head = NULL;
	size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence()
{
	reclaimAllNodes(head);
}    // ~Sequence


template <class T>
void Sequence<T>::clear(void)
{
	reclaimAllNodes(head);
	head = NULL;
} // clear

template <class T>
void Sequence<T>::reclaimAllNodes(NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list
//           beginning with initialP are reclaimed
{
	if (initialP != NULL) {
		reclaimAllNodes(initialP->next);
		delete (initialP);
	} // end if
} // reclaimAllNodes

// You are required to implement add, remove, entry, length, and outputSequence functions here.


template <class T>
void Sequence<T>::add(T& x, int pos)//adds a value to create a sequence.
{
	if (pos < 0 || pos > size)
	{
		cout << "Out of bound" << endl;

		return;
	}
	if (pos == 0)//if NULL
	{
		NodeRecord* temp = new NodeRecord(); //new node
		temp->value = x;
		temp->next = head;
		head = temp;
	}//if
	else//adding a node anywhere on sequence
	{
		NodeRecord* temp = new NodeRecord();
		NodeRecord* current = head;
		temp->value = x;
		for (int i = 0; i < pos - 1; i++)//moves pointer from pointer
		{
			current = current->next;
		}//for
		temp->next = current->next;
		current->next = temp;
	}//else
	size++;
}//add

// post other methods here below add

template <class T>
void Sequence<T>::remove(T& x, int pos)//removes a value from sequence.
{
	if (pos < 0 || pos > size)
	{
		cout << "Out of bound" << endl;

		return;
	}
	if (pos == 0)//moves pointer from head to other node.
	{
		x = head->value;
		head = head->next;

	}//if
	else
	{
		NodeRecord* temp;
		temp = head;
		for (int i = 0; i < pos - 1; i++)
		{
			temp = temp->next;
		}//for
		x = temp->next->value;
		if (pos == size)
			temp->next = NULL;
		else
			temp->next = temp->next->next;
	}
	size--;
}//remove

template <class T>
void Sequence<T>::outputSequence()//Displays a sequence.
{
	if (head == NULL)
	{
		cout << "Empty";
		return;
	}
	NodeRecord* temp;
	temp = head;
	cout << "[";

	while (temp != NULL)//I used a for loop before but it was being funky so I used while
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << "]\n";
}

template <class T>
int Sequence<T>::length()
{
	return size;
}

/*
template <class T>
Sequence<T>& Sequence<T>::operator = (Sequence& rhs)
{
	clear();
	for (int i = 0; i < rhs.length(); i++)
	{
		add(rhs.entry(i), length());
	}
	return (*this);
	//s.operator = (rhs.s)
}

template <class T>
void Sequence<T>::transferFrom(Sequence& source)
{
	clear();
	for (int i = 0; i < source.length(); i++)
	{
		add(source.entry(i), length());
	}
	source.clear();
}
*/

template <class T>
T& Sequence<T>::entry(int pos)//Enters a value in sequence
{

	if (pos < 0 || pos >= size)
	{
		cout << "Out of bounds";
	}
	else
	{
		NodeRecord* temp = head;
		for (int i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}
}

template <class T>
Sequence<T>& Sequence<T>::operator= (Sequence<T>& rhs)
{
	clear();
	for (int i = 0; i < rhs.length(); i++)
	{
		add(rhs.entry(i), length());
	}
	return *this;
	//s.operator = (rhs.s)
}

template <class T>
void Sequence<T>::transferFrom(Sequence<T>& source)
{
	clear();
	for (int i = 0; i < source.length(); i++)
	{
		add(source.entry(i), length());
	}
	source.clear();
}
