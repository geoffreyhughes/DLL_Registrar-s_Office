
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 4: Registrar's Office Simulation
*/


/*
	This source file contains the main function.
	It begins the simulation using the user's provided input file as a command line argument.
	The main function is kept short and sweet.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>


#include "Simulation.h"


using namespace std;

int main(int argc, char** argv)
{

	if (argc <= 1) 
	{
		cout << "Please provide an input file as a command line argument." << endl;
		exit(EXIT_FAILURE);
	}

	simulation theSimulation = simulation(argv[1]);
	theSimulation.simulate();

	return 0;
}
