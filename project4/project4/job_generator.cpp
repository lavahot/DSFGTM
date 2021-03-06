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
#include <cstdlib>
  JobGenerator::JobGenerator( double service_time_distribution_[4],
	double id_distribution_[2],
	double job_create_dist_[3], StatModule* statM ):
	d_job_number(0)
  {
   d_ser_dist = new DiscreteGenerator(4,service_time_distribution_);
   d_id_dist = new DiscreteGenerator(2,id_distribution_);
   d_job_create_dist = new DiscreteGenerator(3,job_create_dist_);
      d_service_times[0]=10;
      d_service_times[1]=20;
      d_service_times[2]=30;
      d_service_times[3]=60;
      stat=statM;
  }

  Job* JobGenerator::gen_jobs_( int& number_jobs_)
  //Returns a pointer to beginning of array of jobs
  // Pointer array could easily be divided int two with
  // the (Job*)+1 on the pointer address
  // Also returns number of jobs generated
  {
   //generate a random number of jobs {0,1,2}
   number_jobs_ = d_job_create_dist->generateDist();
   
      Job* job_ptr = NULL;

   //Fill out the Job*
   if(number_jobs_>0)
   {
    //Make a Job* to the first element
    job_ptr = (Job*) operator new(number_jobs_*sizeof(Job));
       for(int i=0;i<number_jobs_;i++)
    {
     d_job_number++;//The first job shall get number 1
        job_ptr[i] = Job(d_job_number,d_id_dist->generateDist(), d_service_times[d_ser_dist->generateDist()], d_id_dist->generateDist() );
        
    }
   }
      
   return job_ptr;
  }


//JobGenerator was very screwed up. Needed many changes to constructor.
//JobGenerator needs data bout the service times
