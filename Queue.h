#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "DoubleLinkedList.h"
#include "Student.h"

#include "DoubleLinkedList.cpp"


using namespace std;


class Queue {

public:

	Queue();
	~Queue();

	void enqueue(student data);
	student dequeue();
	student peek();



	DoubleLinkedList<student> myDLL;
};

// queue of students
// array of windows (class) 


#endif //QUEUE_H