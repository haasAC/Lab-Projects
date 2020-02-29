#include "Queue.h"
#include <iostream>
#include <cstdio>
using namespace std;

template <class T>
Queue1<T>::Queue1()
{

}// Sequence

template <class T>
Queue1<T>::~Queue1()
{

}    // ~Sequence

template <class T>
void Queue1<T>::enqueue(T& x)
{
	s.add(x, s.length());
}

template <class T>
void Queue1<T>::dequeue(T& x)
{
	s.remove(x, 0);
}

template <class T>
void Queue1<T>::transferFrom(Queue1<T>& source)
{
	s.transferFrom(source.s);
}

template <class T>
Queue1<T>& Queue1<T>::operator= (Queue1<T>& rhs)
{
	s = rhs.s;
	return *this;
	//s.operator= (rhs.s)
}

template <class T>
void Queue1<T>::clear(void)
{
	s.clear();
}


template <class T>
void Queue1<T>::replaceFront(T& x)
{
	T temp = x;
	s.remove(x, 0);
	s.add(temp, 0);
}

template <class T>
T& Queue1<T>::front(void)
{
	return s.entry(0);
}

template <class T>
int Queue1<T>::length(void)
{
	return s.length();
}

template <class T>
void Queue1<T>::outputQueue()
{
	s.outputSequence();
}