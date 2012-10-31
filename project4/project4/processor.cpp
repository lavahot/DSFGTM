/*
 The processor contains the cpu's and a wait queue
*/

/*
class Processor
{
 SortedVector<pair<int,CPU*>> d_cpus;
 QueList<Job*> d_waiting_list;
 public:
*/
#include "processor.h"
#include "cpu.h"
const int NUM_CPUS = 4;

  Processor::Processor(){};
  Processor::Processor(Clock* clock_,StatModule* stat_mod_)
  //Disperse clock to CPU
  {
   std::pair<int,CPU*> cpu_p;
   for(int i=0;i<NUM_CPUS;i++)
   {
    cpu_p.first = i;
    cpu_p.second = new CPU(i,stat_mod_);
    d_cpus.PutItem(cpu_p);
   }
   clock = clock_;
   stat_mod = stat_mod_;
  }

  void Processor::AddJob(Job* job_)
  //Adds a job to the waiting list
  {
   //add job
   d_waiting_list.Enqueue(job_);
  }

  void Processor::LoopCPUCycle()
  //loop through cpu's for the second
  {
   Job* job_p;

   for(int i=0;i<NUM_CPUS;i++)
   {
    while( !((d_cpus[i].second)->IsFull())&& !d_waiting_list.IsEmpty() )
    {
     //record time
     d_waiting_list.Dequeue(job_p);
     job_p->endWaitq(clock->getTime());

     //add to max jobs
     (d_cpus[i].second)->enQ(job_p);
    }

    //run cpu for second
    (d_cpus[i].second)->process(clock->getTime());
   }
  }

//Processor itself needs a stat_mod_ for its que time
