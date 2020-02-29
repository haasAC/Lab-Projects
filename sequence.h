#pragma once
#include <iostream>
#include <cstdio>
//using namespace std;

template <class T>
class Sequence
{
private: // Internal Representation

	class NodeRecord {
	public:
		T value;
		NodeRecord* next;
	};
	NodeRecord* head;
	int size;

public:
	Sequence();
	~Sequence();
	void clear(void);

	//implement the following four functions
	void add(T& x, int pos);
	//! updates self
	//! restores pos
	//! clears x
	//! requires: 0 ≤ pos ≤ |self|
	//! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)

	void remove(T& x, int pos);
	//! updates self
	//! restores pos //! replaces x
	//!requires: 0 ≤ pos < |self|
	//!ensures: <x> = #self[pos, pos+1) and
	//!        self = #self[0, pos) * #self[pos+1, |#self|)

	T& entry(int pos);
	//! restores self, pos
	//! requires: 0 ≤ pos < |self|
	//! ensures: <entry> = self[pos, pos+1)

	int length(void);
	//! restores self
	//! ensures: length = |self|

	void outputSequence(void);
	//! restores self
	//! ensures: self = #self

	void transferFrom(Sequence<T>& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source

	Sequence<T>& operator= (Sequence<T>& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs
	// Queue1 Specific Operations

private: // Internal operations
	void reclaimAllNodes(NodeRecord*& p);
};