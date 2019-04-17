
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 4: Registrar's Office Simulation
*/


/*
	This source file uses the Doubly-Linked List class to create a Queue abstract data type.
	For this assignment all we need to do is insert into the Queue (enqueue), remove from the front of the queue (dequeue), and look at the student at the front of the queue (peek)
	First in, first out!
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Queue.h"


using namespace std;


/*
	Queue Constructor; Creates a DLL with data of type student (taken from the student class defined in Student.cpp)
*/
Queue::Queue() {
	
	 myDLL = DoubleLinkedList<student>();
}


/*
	Queue Destructor; We all must fall...
*/
Queue::~Queue() {


}


/*
	Returns nothing; Inserts a new student at the back of the Queue using DLL
*/
void Queue::enqueue(student data) {

	myDLL.insertBack(data);
}


/*
	Returns a student; Removes the student that is at the front of the queue, and returns it
*/
student Queue::dequeue() {

	return myDLL.removeFront();
}


/*
	Returns nothing; Does not modify the DLL -- only returns the student at the front of the queue
*/
student Queue::peek() {

	return myDLL.peek();
}
