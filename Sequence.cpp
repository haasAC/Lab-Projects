#include <iostream>
#include <cstdio>
using namespace std;

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
	//! requires: 0 ≤ pos < |self|
	//! ensures: <x> = #self[pos, pos+1) and
	//! self = #self[0, pos) * #self[pos+1, |#self|)

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

private: // Internal operations
	void reclaimAllNodes(NodeRecord*& p);
};

typedef Sequence <int> IntegerSequence;


template <class T>
void Sequence<T>::outputSequence(void) 
    {
    if (length() == 0)
    {
        cout << "Sequence Empty" <<endl;
    }
    else
    {
        NodeRecord* current = head;
        int i = 0;
        while (i < length()) 
        {
            cout << current->value <<",";
            current = current->next;
            i++;
        }
        cout << endl;
    }
}

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
void Sequence<T>::clear()
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

template <class T>
int Sequence<T>::length(void)
{
	return size;
}

template <class T>
T& Sequence<T>::entry(int pos)
{
	if (length() == 0)
	{
		cout << "Empty" << endl;

	}
	else {
		NodeRecord* current = head;
		int i = 0;
		while (i < pos) {
			current = current->next;
			i++;

		}
		return current->value;
	}
}

template <class T>
void Sequence <T>::add(T& x, int pos)
{
	NodeRecord *n = new NodeRecord;
	n->value = x;
	n->next = NULL;

	if (length() == 0) {
		head = n;
		size++;
	}
	else if (pos == 0) {
		n->next = head;
		head = n;
		size++;
	}
	else if (pos <= length()) {
		NodeRecord *current = head;
		int i = 0;
		while (i < pos - 1) {
			current = current->next;
			i++;
		}
		n->next = current->next;
		current->next = n;
		size++;
	}

}

template <class T>
void Sequence <T> ::remove(T& x, int pos)
{
	NodeRecord *n = new NodeRecord;
	n->value = x;
	n->next = NULL;

	if (length() == 0)
	{
		cout << "Empty" << endl;
	}
	else if (pos == 0)
	{
		x = head->value;
		head = head->next;
		size--;
	}
	else if (pos < length())
	{
		NodeRecord *current = head;
		int i = 0;
		while (i < pos - 1)
		{
			current = current->next;
			i++;
		}
		x = current->next->value;
		current->next = current->next->next;
		size--;
	}

}


//----------------------------------------------

bool resNegative(int i, IntegerSequence& source)
{
	bool allNegative = true;
	for (int j = i; j < source.length() && allNegative; j++)
	{
		if (source.entry(j) > 0)
			allNegative = false;
	}
	return allNegative;
}


void negativesToEnd(IntegerSequence& source)
{
    int i, temp;
    for (i = 0; i<source.length() && !resNegative(i,source); i++) {
        if (source.entry(i) < 0 )
        {
            source.remove(temp,i);
            source.add(temp,source.length());
        }
    }
}


   
int main() {

	Sequence<int>* check = new Sequence<int>();
	IntegerSequence seq;
    
    int x = 12;
    check->add(x,0);
    check->outputSequence();
    
    int y = -21;
    check->add(y,1);
    check->outputSequence();
    
    int z = 31;
    check->add(z,2);
    check->outputSequence();
    
    int a = -61;
    check->add(a,3);
    check->outputSequence();
    
    int b = 98;
    check->add(b,4);
    check->outputSequence();
    
    int c = -78;
    check->add(c,5);
    check->outputSequence();    
    
    int p = 57;
    check->add(p,6);
    check->outputSequence();   
        
    check->remove(p,6);
    check->outputSequence();
    
    check->remove(a,3);
    check->outputSequence();
    
    check->remove(c,4);
    check->outputSequence();
    
    check->remove(y,1);
    check->outputSequence();
    
    check->remove(b,2);
    check->outputSequence();
    
    check->remove(z,1);
    check->outputSequence();
    
    check->remove(x,0);
    check->outputSequence();
    //----------------------
    cout << endl;
    //----------------------
    int q = -47;
	seq.add(q, 0);
	
    q = 10;
	seq.add(q, 1);

    q = 57;
	seq.add(q, 2);

    q = 9;
	seq.add(q, 3);

    q = -33;
	seq.add(q, 4);

    q = -12;
	seq.add(q, 5);

    q = -17;
	seq.add(q, 6);
    
    
    seq.outputSequence();
	negativesToEnd(seq);
	seq.outputSequence();
    
	return 0;
}
