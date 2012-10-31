/*
 Generates jobs for the simulation
*/

#ifndef JOB_GENERATOR_H
#define JOB_GENERATOR_H
#include "discrete_generator.h"
#include "job.h"

class JobGenerator
{
 int d_job_number;
 DiscreteGenerator* d_ser_dist;
 //service time distribution
 DiscreteGenerator* d_id_dist;
 //distribution of id
 DiscreteGenerator* d_job_create_dist;
 //distribution of job creations( 0,1,2 ) per cycle
    
    float d_service_times[4];
 public:
    JobGenerator(double [], double [], double[]);
  void init( double service_time_distribution_[4],
	double* id_distribution_,
	double*  );
  Job* gen_jobs_( int& number_jobs_);
  //Returns a pointer to beginning of array of jobs
  // Pointer array could easily be divided int two with
  // the (Job*)+1 on the pointer address
  // Also returns number of jobs generated
};
#endif
