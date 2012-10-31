/*
 Generates jobs for the simulation
*/

/*
 int d_job_number;
 DiscreteGenerator d_ser_dist;
 //service time distribution
 DiscreteGenerator d_id_dist;
 //distribution of id
 DiscreteGenerator d_job_create_dist;
 //distribution of job creations( 0,1,2 ) per cycle
 double d_service_times[4];
*/

#include "job_generator.h"
#include "discrete_generator.h"
  void JobGenerator::init( double service_time_distribution_[4],
	double id_distribution_[2],
	double job_create_dist_[3] ):
	d_job_number(0)
  {
   d_ser_dist(4,service_time_distribution_);
   d_id_dist(2,id_distribution_);
   d_job_create_dist(3,job_create_dist_);
  }

  Job* JobGenerator::gen_jobs_( int& number_jobs_)
  //Returns a pointer to beginning of array of jobs
  // Pointer array could easily be divided int two with
  // the (Job*)+1 on the pointer address
  // Also returns number of jobs generated
  {
   //generate a random number of jobs {0,1,2}
   int number_jobs_ = d_job_create_dist.generate();
   
   Job* job_ptr = NULL;

   //Fill out the Job*
   if(number_jobs_>0)
   {
    //Make a Job* to the first element
    job_ptr = operator new(number_jobs_*sizeof(Job));
    for(int i=0;i<number_jobs_:i++)
    {
     d_job_number++;//The first job shall get number 1
     job_ptr[i] = Job(d_job_number,d_id_dist.generate(), d_service_times[d_ser_dist.generate()] );
    }
   }

   return job_ptr;
  }


//JobGenerator was very screwed up. Needed many changes to constructor.
//JobGenerator needs data bout the service times
