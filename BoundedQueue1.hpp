#pragma once

/*
	Realization of BoundedQueue using StaticArray
	Author: Dr. Holly
*/

#include "StaticArray\StaticArray1.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T, int maxLength>
class BoundedQueue1
		//! requires: 1 <= maxLength

		//! is modeled by string of T
		//! exemplar self
		//! constraint |self| <= maxLength
{
public: // Standard Operations
	BoundedQueue1 ();
		//! replaces self
		//! ensures: self = <>
	~BoundedQueue1 ();
	void clear (void);
		//! clears self
	void transferFrom (BoundedQueue1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	BoundedQueue1& operator = (BoundedQueue1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// BoundedQueue1 Specific Operations
	void enqueue (T& x);
		//! updates self
		//! clears x
	    //! requires |self| + 1 <= maxLength
		//! ensures: self = #self * <#x>
	void dequeue (T& x);
		//! updates self
		//! replaces x
		//! requires: self /= <>
		//! ensures: <x> is prefix of #self  and  
		//!          self = #self[1, |#self|)
	void replaceFront (T& x);
		//! updates self, x
		//! requires: self /= <>
		//! ensures: <x> is prefix of #self  and
		//!          self = <#x> * #self[1, |#self|)
	T& front(void);
		//! restores self
		//! requires: self /= <>
		//! ensures: <front> is prefix of self
	Integer length (void);
		//! restores self
		//! ensures: length = |self|
	Integer remainingCapacity (void);
		//! restores self
		//! ensures: remainingCapacity = maxLength - |self|

	friend wostream& operator << <T, maxLength>(wostream& os, BoundedQueue1<T, maxLength>& q);
		//! updates os
		//! restores q

private: // Representation
	
	enum { lowerBound = 0, upperBound = (maxLength - 1) };
	typedef StaticArray1 <T, lowerBound, upperBound> ArrayOfT;

	ArrayOfT contents;
	Integer currentLength;

	// correspondence self = IteratedConcatenation(z:Integer 0 <= z < currentLength, <contents(z)>)

	// convention 0 <= currentLength < maxLength

private: // Local Operations
	void displayRep(wostream& os);

private: // Disallowed BoundedQueue1 Operations
	BoundedQueue1(const BoundedQueue1& s);
	BoundedQueue1* operator &(void) {return this;};
	const BoundedQueue1* operator &(void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedQueue1<T, maxLength>::displayRep(wostream& os)
//! ensures: contents = #contents  and  
//!          currentLength = #currentLength  and  
//!          maxLength = #maxLength  and
//!          the values for each data member (contents, currentLength, maxLength) are displayed
{
	os << endl;
	os << "     contents: " << contents << endl;
	os << "currentLength: " << currentLength << endl;
	os << "    maxLength: " << maxLength << endl;
} // displayRep

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T, int maxLength>
BoundedQueue1<T, maxLength>::BoundedQueue1 ()
{
}	// BoundedQueue1

//-----------------------------------------------------------------------

template <class T, int maxLength>
BoundedQueue1<T, maxLength>::~BoundedQueue1 ()
{
}	// ~BoundedQueue1

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedQueue1<T, maxLength>::clear(void)
{
	contents.clear();
	currentLength.clear();
}	// clear

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedQueue1<T, maxLength>::transferFrom (BoundedQueue1& source)
{
	contents.transferFrom(source.contents);
	currentLength.transferFrom(source.currentLength);
} // transferFrom

//-----------------------------------------------------------------------

template <class T, int maxLength>
BoundedQueue1<T, maxLength>& BoundedQueue1<T, maxLength>::operator = (BoundedQueue1& rhs)
{
	contents = rhs.contents;
	currentLength = rhs.currentLength;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedQueue1<T, maxLength>::enqueue (T& x)
{
	contents[currentLength].transferFrom(x);
	currentLength++;
}	// enqueue

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedQueue1<T, maxLength>::dequeue(T& x)
{
	static Integer locationZero = 0;

	x.transferFrom(contents[locationZero]);
	for (int k = 0, z = (currentLength - 1); k < z; k++) {
		contents[k].transferFrom(contents[k + 1]);
	} // end for
	currentLength--;
}	// dequeue

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedQueue1<T, maxLength>::replaceFront (T& x)
{
	static Integer locationZero = 0;
	T temp;

	temp.transferFrom(contents[locationZero]);
	contents[locationZero].transferFrom(x);
	x.transferFrom(temp);
}	// replaceFront

//-----------------------------------------------------------------------

template <class T, int maxLength>
T& BoundedQueue1<T, maxLength>::front(void)
{
	static Integer locationZero = 0;

	return contents[locationZero];
}  // front

//-----------------------------------------------------------------------

template <class T, int maxLength>
Integer BoundedQueue1<T, maxLength>::length (void)
{
	return currentLength;
}	// length

//-----------------------------------------------------------------------

template <class T, int maxLength>
Integer BoundedQueue1<T, maxLength>::remainingCapacity(void)
{
	return maxLength - currentLength;
}	// remainingCapacity

//-----------------------------------------------------------------------

template <class T, int maxLength>
wostream& operator<< (wostream& os, BoundedQueue1<T, maxLength>& q)
{
#ifdef NDEBUG
	os << L"<";
	for (int k = 0, z = q.length(), lastItem = z - 1; k < z; k++) {
		T x;

		q.dequeue(x);
		os << x;
		q.enqueue(x);
		if (k < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L">";
#else
	q.displayRep(os);
#endif
	return os;
} // operator<<



