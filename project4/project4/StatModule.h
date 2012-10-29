#ifndef STATMODULE
#define STATMODULE
#ifndef JOB
//#DEFINE JOB
#include "job.h"
#endif

#include <fstream>

class StatModule
{
	private:
		struct stats
		{
			int avgWaitQ;
			int avgCPUQ;
			int numOfType;
			
		};
		stats jobStatArry[2][4][2];
        //array arranged like so:
        //first element determines type e.g. IO=0, CPU=1
        //second element indicates run time requirement
        //[0] 10 sec run time
        //[1] 20 sec run time
        //[2] 30 sec run time
        //[3] 60 sec run time
        //the third element is the total number and time in queue for the job respectively
    
        
    
		float CPUIdle[10];
	public:
		StatModule();
		~StatModule();
		void reportJobEnd(Job *jobend);
		void reportJobBegin(Job *jobbegin);
		void reportCPUIdle(float);
		void printStats();		
};

	StatModule::StatModule()
	{}
	StatModule::~StatModule()
	{}
	void StatModule::reportJobEnd(Job *job)
	{
        
	}

#endif