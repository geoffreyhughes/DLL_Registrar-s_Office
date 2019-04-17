
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 4: Registrar's Office Simulation
*/


/*
	This source file impliments the student class.
	Each instance of student created is done so using the time they arrived, and the time they will require at a window.
	A queue of students is made in Simulation.cpp's simulate() function.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "DoubleLinkedList.h"
#include "ListNode.h"
#include "Student.h"

using namespace std;


/*
	Base Student Constructor; (Unused)
*/
student::student() {


}


/*
	Student Constructor that takes parameter (int timeA); this creates a student and defines their timeNeeded with timeA
*/
student::student(int timeA) {

	timeNeeded = timeA;

}


/*
	Student Constructor that takes parameters (int timeA, int timeN); this creates a student and defines their timeArrived and timeNeeded
	It also sets their initial timeWaiting to 0 (minutes).
*/
student::student(int timeA, int timeN) {

	timeArrived = timeA;
	timeNeeded = timeN;

	timeWaiting = 0;

}


/*
	Student Destructor; Please don't use this on me!
*/
student::~student() {




}
