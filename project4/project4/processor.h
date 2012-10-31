#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "clock.h"
#include "StatModule.h"
#include "sorted_vector.h"
#include "que_list.h"
#include "cpu.h"
#include <utility>
/*
 The processor contains the cpu's and a wait queue
*/
class Processor
{
 typedef class CPU* CPUP;
 typedef std::pair<int,CPUP> thePair;
 SortedVector< thePair > d_cpus;
 QueList<Job*> d_waiting_list;
    Clock* clock;
    StatModule* stat_mod;
 public:
  Processor();
  Processor(Clock*,StatModule*);
  //Disperse clock to CPU
  void AddJob(Job* job_);
  //Adds a job to the waiting list
  void LoopCPUCycle();
  //loop through cpu's for the second
};

#endif
