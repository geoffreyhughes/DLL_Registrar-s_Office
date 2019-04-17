
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 4: Registrar's Office Simulation
*/


/*
	This source file contains the simulation, which uses all the other classes to compute the required metrics.
	The simulation class holds key information needed to run its most important function: simulate();
	The simulate function is where the queue of students and array of windows are created, interact, and used to output metrics.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>


#include "Window.h"
#include "Queue.h"
#include "Simulation.h"


using namespace std;


/*
	Base Simulation Constructor; (unused);
*/
simulation::simulation() {

}


/*
	Simulation Constructor that takes a string parameter; 
	Used to construct the main simulation that reads from the user's input file, fileName
*/
simulation::simulation(string fileName) {

	dataFile = fileName;
	loopContinue = true;

	numWindows = 0;
	numStudents = 0;

}


/*
	Simulation Destructor; What would life be without death?
*/
simulation::~simulation() {


}


/*
	The simulate() function is where the queue of students and array of windows are created, interact, and used to output metrics.
	This is where everything comes together.
	This function returns nothing, but it outputs (cout) the required labeled metrics.
	It does the bulk of the project: the actual Registrar's Office simulation
*/
void simulation::simulate() {

	Queue studentQueue = Queue();

    ifstream inFile;
    inFile.open(dataFile);

    string str = "";
    int lineNumber = 1;
    int currTime = 0;
    int studentsToArrive = 0;
    bool timeChange = true;

/*
	Read in from the input file:
		Create students and enqueue them with appropriate time data
		Create an array of windows
*/
    while(getline(inFile, str))
    {
    	if (lineNumber == 1)
    	{
    		numWindows = stoi(str);
    	}

    	else if (studentsToArrive == 0 && timeChange)
    	{
    		currTime = stoi(str);
    		timeChange = false;
    	}

    	else if (studentsToArrive == 0 && !timeChange)
    	{
    		studentsToArrive = stoi(str);
    	}

    	else
    	{
    		studentQueue.enqueue(student(currTime, stoi(str)));
    		++numStudents;
    		--studentsToArrive;

    		if (studentsToArrive == 0) 
    		{
    			timeChange = true;
    		}
    	}
    	++lineNumber;
    }
	inFile.close();


	// Create dynamic window array
	window *windowArray = new window[numWindows];
	for (int i = 0; i < numWindows; ++i)
	{
		windowArray[i] = window();
	}


	// Create an array of integers to hold student wait times
	int numStudentsOG = numStudents;
	int studentWaitTimes[numStudents];
	for (int i = 0; i < numStudents; ++i)
	{
		studentWaitTimes[i] = -1;
	}


// Done creating QUEUE OF STUDENTS and ARRAY OF WINDOWS 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Now we simulate the students interacting with the windows (main meaty loop)

	int simulationTime = 0;
	bool openWindow = false;
	int openWindowNumber = -1;
	bool allWindowsOpen = false;
	int studentServiced = 0;


	while (loopContinue)
	{

		// Update each occupied window's remaining timeStudentNeeds
		// Open windows if they no longer have a student (timeStudentNeeds == 0)
		for (int i = 0; i < numWindows; ++i) 
		{
			if (windowArray[i].isOpen == false)
			{
				--windowArray[i].timeStudentNeeds;

				if (windowArray[i].timeStudentNeeds == 0)
				{
					windowArray[i].isOpen = true;
				}
			}
		}


		// At this time, if a student exists at the front of the line,
		// place them in an open window, if one exists. Continue until no student exists at this simulationTime;
		while (numStudents >= 1 && studentQueue.peek().timeArrived <= simulationTime)
		{
			// Find an open window, if one exists
			openWindow = false;
			for (int i = 0; i < numWindows; ++i)
			{
				if (windowArray[i].isOpen)
				{
					openWindow = true;
					openWindowNumber = i;
				}
			}

			// If a window is open, remove student from queue
			// Record required student metrics, and update the window's instance variables
			if (openWindow)
			{
				studentWaitTimes[studentServiced] = simulationTime - studentQueue.peek().timeArrived;
				++studentServiced;

				windowArray[openWindowNumber].isOpen = false;
				windowArray[openWindowNumber].timeStudentNeeds = studentQueue.dequeue().timeNeeded;
				--numStudents;
			}

			// If no window is open for our waiting student, break from this loop
			else
			{
				break;
			}
		}


		// Update if allWindowsOpen
		allWindowsOpen = true;
		for (int i = 0; i < numWindows; ++i)
		{
			if (windowArray[i].isOpen == false)
			{
				allWindowsOpen = false;
			}
		}


		// End simulation if there are no students left, and all windows are open
		if (numStudents == 0 && allWindowsOpen)
		{
			loopContinue = false;
			break;
		}


		// If a window is still open at the end of current time, incriment its idleTime
		for (int i = 0; i < numWindows; ++i)
		{
			if (windowArray[i].isOpen == true)
			{
				++windowArray[i].timeIdle;
			}
		}


		simulationTime++;
	} // END OF main simulation loop



	/*
		Done with simulating the Registrar's Office...
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Now we compute metrics using our completed
		studentWaitTimes[] and windowArray[].timeIdle
	*/



	double meanStudentWT = 0.0;
	double medianStudentWT = 0.0;
	int longestStudentWT = 0;
	int numStudentsWTover10 = 0;

	double meanWindowIT = 0.0;
	int longestWindowIT = 0;
	int numWindowsITover5 = 0;


	// Compute 1. mean student wait time
	for (int i = 0; i < numStudentsOG; ++i)
	{
		meanStudentWT += studentWaitTimes[i];
	}
	meanStudentWT /= double(numStudentsOG);


	// Compute 2. median student wait time
	for (int i = 0; i < numStudentsOG; ++i)
	{
		int min = studentWaitTimes[i];
		int minIndex = i;
		int temp = 0;

		for (int j = i; j < numStudentsOG; ++j)
		{
			if (studentWaitTimes[j] < min)
			{
				min = studentWaitTimes[j];
				minIndex = j;
			}
		}

		studentWaitTimes[minIndex] = studentWaitTimes[i];
		studentWaitTimes[i] = min;
	}
	if (numStudentsOG % 2 == 0)
	{
		int leftMedian = 0;
		int rightMedian = 0;

		leftMedian = numStudentsOG / 2;
		rightMedian = (numStudentsOG) / 2 + 1;

		medianStudentWT = (double(studentWaitTimes[--leftMedian]) + double(studentWaitTimes[--rightMedian])) / 2.0;
	}
	else
	{
		int median = numStudentsOG / 2;
		++median;
		medianStudentWT = studentWaitTimes[--median];
	}


	// Compute 3. longest student wait time
	longestStudentWT = studentWaitTimes[numStudentsOG - 1];


	// Compute 4. # of students waiting over 10 minutes
	for (int i = 0; i < numStudentsOG; ++i)
	{
		if (studentWaitTimes[i] > 10)
		{
			++numStudentsWTover10;
		}
	}


	// Compute 5. mean window idle time
	for (int i = 0; i < numWindows; ++i)
	{
		meanWindowIT += windowArray[i].timeIdle;
	}
	meanWindowIT /= double(numWindows);


	// Compute 6. longest window idle time
	for (int i = 0; i < numWindows; ++i)
	{
		if (windowArray[i].timeIdle > longestWindowIT)
		{
			longestWindowIT = windowArray[i].timeIdle;
		}
	}


	// Compute 7. # of windows idle for over 5 minutes
	for (int i = 0; i < numWindows; ++i)
	{
		if (windowArray[i].timeIdle > 5)
		{
			++numWindowsITover5;
		}
	}


	// Now the fun part! cout all the precious information...
	cout << endl;
	cout << "/*********************************************" << endl;
	cout << "/ 1. Mean student wait time: " << meanStudentWT << endl;
	cout << "/ 2. Median student wait time: " << medianStudentWT << endl;
	cout << "/ 3. Longest student wait time: " << longestStudentWT << endl;
	cout << "/ 4. # of students waiting over 10 minutes: " << numStudentsWTover10 << endl << "/" << endl;;
	cout << "/ 5. Mean window idle time: " << meanWindowIT << endl;
	cout << "/ 6. Longest window idle time: " << longestWindowIT << endl;
	cout << "/ 7. # of windows idle for over 5 minutes: " << numWindowsITover5 << endl;
	cout << "**********************************************" << endl << endl;


	// Delete dynamically allocated array windowArray[]
	delete[] windowArray;
}
