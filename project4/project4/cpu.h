#ifndef CPU_H
#define CPU_H

#include "job.h"
#include "que_list.h"
#include "StatModule.h"


class CPU
{
	private:
		QueList<Job*> *jobQue;
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

#endif
