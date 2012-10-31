#ifndef SIMENGINE_H
#define SIMENGINE_H
/*
 Responsibilities:
  Simulate CPU scheduling
  Contains loop
   Job generator
   processor
   clock
 Collaborators
  Stat module
  interface for collecting
  statistical data
*/
#include "processor.h"
#include "job_generator.h"

class SimEngine
{
 Processor* proc;
 Clock* clock;
 JobGenerator* job_gen;
 int num_jobs;
 StatModule* stat;
 public:
  SimEngine(StatModule* stat_mod_, 
	double p_jobs_per_cycle_distribution_[3],
	double p_service_time_distribution_[4],
	double p_job_id_distribution_[2] ,
    int num_jobs_);//alloc clock
  //Distribute StatModule
  void Sim();
  //Runs the simulation to completion
  ~SimEngine();
  //dealloc clock
};
#endif
