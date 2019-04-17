#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "DoubleLinkedList.h"
#include "ListNode.h"

using namespace std;

class student {


public:

	student();
	student(int timeA);
	student(int timeA, int timeN);
	~student();

	int timeArrived;
	int timeNeeded;

	int timeWaiting;
	


};

#endif //STUDENT_H