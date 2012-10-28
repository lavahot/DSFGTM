#ifndef CPU
#define CPU

#ifndef JOB
//#DEFINE JOB
#include "job.h"
#endif

#ifndef QUE_LIST_H
//#DEFINE QUE_LIST_H
#include "que_list.h"
#endif

#ifndef STATMODULE
#include "StatModule.h"
#endif

class CPU
{
	private:
		QueList<*Job> jobQue (5);
		float idletime;
		float jobtime;
		int queLength;
		int ID;
		StatModule *statM;
	public:
		CPU();
		CPU(int newID, StatModule *stat);
		~CPU();
		int process(int ctime);
		bool enQ(Job *jobitem);
		bool IsFull();
};
	CPU::CPU()
	{
		idletime=0.0;
	}
	CPU::CPU(int newID, StatModule *stat)
	{
		statM=stat;
		ID=newID;
		idletime=0.0;
	}
	CPU::~CPU()
	{
	}
	int CPU::process(int ctime)
	{
		jobtime=1;
		Job *jobTmp;
		if (!jobQue.isEmpty())
		{
			queLength=jobQue.GetLength();
			for(int i = 0; i<queLength; i++)
			{
				jobQue.Dequeue(jobTmp);
				if(jobTmp.process())
					jobQue.Enqueue(jobTmp);
				else
				{
					jobTmp.endCPUq(ctime);
					statM->reportJobEnd(jobTmp);
					
					delete jobTmp;
				}
			}
			
		}
		return idletime;
		
	}
	bool CPU::enQ(Job *jobitem)
	{ 
		if (!jobQue.isFull())
		{
			jobQue.Enqueue(jobitem);
			return true;//job queue has room, item enqueued.
		}
		else
			return false;//queue is full, try later.
	}
	bool CPU::IsFull()
	{
		return jobQue.IsFull();
	}
#ENDIF