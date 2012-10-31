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
 bool incorrect;

do {
 cout << endl << "Enter the jobs per cycle distribution" << endl;
 cout << "Probability of 0 jobs: "; cin>> p_job_per_cycle[0];
 cout << "Probability of 1 jobs: "; cin>> p_job_per_cycle[1];
 cout << "Probability of 2 jobs: "; cin>> p_job_per_cycle[2];

 incorrect=(p_job_per_cycle[0]<0.||p_job_per_cycle[1]<0.||\
	p_job_per_cycle[2]<0.||(p_job_per_cycle[0]+p_job_per_cycle[1]+p_job_per_cycle[2])>1.);
}while(incorrect);
 fout << "Probability of 0 jobs: "; fout<< p_job_per_cycle[0] << endl;
 fout << "Probability of 1 jobs: "; fout<< p_job_per_cycle[1] << endl;
 fout << "Probability of 2 jobs: "; fout<< p_job_per_cycle[2] << endl;

do {
 cout << endl << "Enter the service time distribution" << endl;
 cout << "Probability of service time 10.0: "; cin>> p_serv_time_dist[0];
 cout << "Probability of service time 20.0: "; cin>> p_serv_time_dist[1];
 cout << "Probability of service time 30.0: "; cin>> p_serv_time_dist[2];
 cout << "Probability of service time 60.0: "; cin>> p_serv_time_dist[3];

 incorrect=(p_serv_time_dist[0]<0.||p_serv_time_dist[1]<0.||\
	p_serv_time_dist[2]<0.|| p_serv_time_dist[3]<0.||\
	(p_serv_time_dist[0]+p_serv_time_dist[1]+p_serv_time_dist[2]+p_serv_time_dist[3])>1.);
}while(incorrect);
 fout << "Probability of service time 10.0: "; fout<< p_serv_time_dist[0] << endl;
 fout << "Probability of service time 20.0: "; fout<< p_serv_time_dist[1] << endl;
 fout << "Probability of service time 30.0: "; fout<< p_serv_time_dist[2] << endl;
 fout << "Probability of service time 60.0: "; fout<< p_serv_time_dist[3] << endl;

do {
 cout << endl << "Enter the id distribution" << endl;
 cout << "Probability of Proc jobs: "; cin>> p_job_id[0];
 cout << "Probability of IO jobs: "; cin>> p_job_id[1];

 incorrect=(p_job_id[0]<0.||p_job_id[1]<0.||(p_job_id[0]+p_job_id[1]>1.));
}while(incorrect);
 fout << "Probability of Proc jobs: "; fout<< p_job_id[0] << endl;
 fout << "Probability of IO jobs: "; fout<< p_job_id[1] << endl;

do{
 cout << endl << "Enter the total number of jobs" << endl;
 cout << "Number of jobs: "; cin >> num_jobs;
}while(num_jobs<=0);
 fout << "Number of jobs: "; fout<< num_jobs << endl << endl << endl;

 SimEngine sim_eng(stat_mod, 
	p_job_per_cycle,
	p_serv_time_dist,
	p_job_id ,
	num_jobs);
 sim_eng.Sim();
 stat_mod->printStats();
    
 fout.close();
}

