#ifndef WINDOW_H
#define WINDOW_H


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "DoubleLinkedList.h"
#include "ListNode.h"

using namespace std;

class window {


public:

	window();
	~window();

	bool isOpen;

	int timeIdle;
	int timeStudentNeeds;


};

#endif //WINDOW_H