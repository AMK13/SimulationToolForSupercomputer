// SimulatorForSupercomputer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "SimulationTool.h"
int _CLOCK_ = 0;
using namespace std;

int main()
{

	//parameters from console, only for user->student
	int amountOfJob = 60;
	int amountOfJobPerUser = 2;		//per student
	int amountOfUsers = 30;			//students
	int amountOfUsersPerGroup = 10; // per course
	int budget = 100;
	
	//create environment
	SimulationTool simulationTool(amountOfUsersPerGroup, budget);

	//each student creates job in "real-time"
	vector<int> delay;
	delay = simulationTool.ExponentialDistributionEngine(amountOfJob, 20, amountOfJobPerUser); 
	for (int i = 0; i < amountOfUsersPerGroup; i++)
	{
		simulationTool.users->course[0].student[i].CreateJob(2, delay); 
		simulationTool.users->course[1].student[i].CreateJob(2, delay);
		simulationTool.users->course[2].student[i].CreateJob(2, delay);
	}

	//jobs are in queue
 	simulationTool.RunScheduler();  
	
	//add resources, leave queue, execute
	while (simulationTool.scheduler->AmountOfJob(Queue::_short) != 0)
	{
		//add to job resources
		simulationTool.MatchJobToResources();
	
		//jobs are remove from queue and execute
		simulationTool.ExecuteJobs();		
	}

	//copy of data
	vector <Job> *copy = new vector<Job>;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				copy->push_back(simulationTool.users->course[i].student[j].GetJob(k));
			}
		}	
	}

	//Simulation information
	cout << "--SIMULATION INFORMATION (time in imaginary time units)--\n";
	cout << "CREATE TIME \t\t PUT_IN_QUEUE_TIME \t\t IN_QUEUE_TIME \t\t EXECUTION_TIME \t\t\n";

	for (int i = 0; i < 60; i++)
	{
		
	}




}


