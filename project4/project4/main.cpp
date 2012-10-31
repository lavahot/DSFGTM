//
//  main.cpp
//  project4
//
//  Created by Taylor Mansfield on 10/28/12.
//  Copyright (c) 2012 Taylor Mansfield. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "StatModule.h"
#include "sim_engine.h"

using namespace std;

int main()
{
 ofstream fout( "StatOutput.txt" );

 StatModule *stat_mod = new StatModule(fout);
 double p_job_per_cycle[3];
 double p_serv_time_dist[4];
 double p_job_id[2];
 int num_jobs;

 cout << endl << "Enter the jobs per cycle distribution" << endl;
 cout << "Probability of 0 jobs: "; cin>> p_job_per_cycle[0];
 cout << "Probability of 1 jobs: "; cin>> p_job_per_cycle[1];
 cout << "Probability of 2 jobs: "; cin>> p_job_per_cycle[2];

 cout << endl << "Enter the service time distribution" << endl;
 cout << "Probability of service time 10.0: "; cin>> p_serv_time_dist[0];
 cout << "Probability of service time 15.0: "; cin>> p_serv_time_dist[1];
 cout << "Probability of service time 20.0: "; cin>> p_serv_time_dist[2];
 cout << "Probability of service time 30.0: "; cin>> p_serv_time_dist[3];

 cout << endl << "Enter the id distribution" << endl;
 cout << "Probability of Proc jobs: "; cin>> p_job_id[0];
 cout << "Probability of IO jobs: "; cin>> p_job_id[1];

 cout << endl << "Enter the total number of jobs" << endl;
 cout << "Number of jobs: "; cin >> num_jobs;

 SimEngine sim_eng(stat_mod, 
	p_jobs_per_cycle_distribution,
	double p_service_time_distribution,
	p_job_id_distribution ,
	num_jobs);
 sim_eng.Sim();
 stat_mod.printstats();
    
 fout.close();
}

