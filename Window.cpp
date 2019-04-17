/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 4: Registrar's Office Simulation
*/


/*
	This source file impliments the Window class.
	There is not much to this class -- it is used to keep track of window availability in the Simulation class.
	An array of windows is made in Simulation.cpp's simulate() function.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Window.h"


/*
	Window Constructor; Defines all instance variables to their default modes. 
	AKA an open window with no student in it, and no timeIdle... yet
*/
window::window() {

	isOpen = true;
	timeIdle = 0;
	timeStudentNeeds = 0;
}


/*
	Window Destructor; Even more effective than a baseball.
*/
window::~window() {

}