
#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>


#include "Queue.h"



using namespace std;


class simulation {

public:

	simulation();
	simulation(string fileName);
	~simulation();

	bool loopContinue;
	string dataFile;

	int numWindows;
	int numStudents;


	void simulate();
};


#endif //SIMULATION_H