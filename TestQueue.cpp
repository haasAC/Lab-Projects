#include"Queue.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	typedef Queue1<int> IntegerQueue;
	IntegerQueue q1, q2, q3;


	int x = 5;
	q1.enqueue(x);
	x = 23;
	q1.enqueue(x);
	x = 34;
	q1.enqueue(x);
	x = 55;
	q1.enqueue(x);
	cout << "Queue 1: ";
	q1.outputQueue();


	cout << "Length of Queue " << q1.length() << endl;


	q1.dequeue(x);
	cout << "Number dequeueing: " << x << endl;
	cout << "Queue after dequeueing: ";
	q1.outputQueue();
	cout << "Length of Queue " << q1.length() << endl;

	cout << "Queue before replacing front ";
	q1.outputQueue();

	x = 99;
	q1.replaceFront(x);
	cout << "Queue after replacing front ";
	q1.outputQueue();
	cout << "Number replaced: " << x << endl;

	cout << "Length of Queue " << q1.length() << endl;

	cout << "Front of the Queue " << q1.front() << endl;

	cout << "Queue 2 before ";
	q1.outputQueue();

	q2.transferFrom(q1);
	cout << "Queue 2 after ";
	q2.outputQueue();
	cout << "Queue 1 after ";
	q1.outputQueue();

	q3 = q2;
	cout << "\nQueue 3 after operatror= ";
	q3.outputQueue();

	typedef Queue1<string> TextQueue;
	TextQueue q4, q5, q6;

	string y = "My";
	q4.enqueue(y);
	y = "Name";
	q4.enqueue(y);
	y = "is";
	q4.enqueue(y);
	y = "Harris";
	q4.enqueue(y);
	cout << "Queue of String ";
	q4.outputQueue();

	cout << "Length of Queue " << q4.length() << endl;

	q4.dequeue(y);
	cout << "String dequeueing: " << y << endl;
	cout << "Queue after dequeueing: ";
	q4.outputQueue();

	cout << "Length of Queue " << q4.length() << endl;

	cout << "Queue 5 before ";
	q5.outputQueue();
	cout << endl;
	q5.transferFrom(q4);
	cout << "Queue 5 after ";
	q5.outputQueue();
	cout << "Queue 4 after ";
	q4.outputQueue();

	q6 = q5;
	cout << "\nQueue 6 after operatror= ";
	q6.outputQueue();
	cout << "Queue 5 after operator= ";
	q5.outputQueue();

}