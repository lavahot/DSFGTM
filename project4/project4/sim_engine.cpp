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

/*
class SimEngine
{
 Processor proc;
 Clock* clock;
 JobGenerator job_gen;
 public:
*/
#include "sim_engine.h"
#include "processor.h"
  SimEngine::SimEngine(StatModule* stat_mod_, 
	double p_jobs_per_cycle_distribution_[3],
	double p_service_time_distribution_[4],
	double p_job_id_distribution_[2] ,
	int num_jobs_)//alloc clock
  //Distribute StatModule
  {
   clock=new Clock();
   job_gen = new JobGenerator( p_service_time_distribution_,p_job_id_distribution_,p_jobs_per_cycle_distribution_, stat_mod_);
   proc= new Processor(clock,stat_mod_);
   num_jobs = num_jobs_;
      stat=stat_mod_;
  }

  void SimEngine::Sim()
  //Runs the simulation to completion
  {
   Job* job_p;
      int num_jobstmp=0;
   //run simulation loop
   for(int i=0; i<num_jobs; )
   {
    //update clock
    clock->advTime();

    //get jobs
    job_p = job_gen->gen_jobs_(num_jobstmp);

    //put jobs in processor
    for(int j=0; j<num_jobstmp; j++ )
     proc->AddJob(job_p+j);
       i+=num_jobstmp;
    //run processor
    proc->LoopCPUCycle();
       /*
    if( i%60==0 )
    {
        stat->printStatus(clock->getTime());
    }*/
   }
  }

  SimEngine::~SimEngine()
  //dealloc clock
  {
   delete clock;
      delete proc;
  }

//total time needed to be added to SimEngine
//The constructor now takes a 3-double for jobs per cycle.
