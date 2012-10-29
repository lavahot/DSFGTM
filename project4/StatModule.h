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
		stats jobStatArry[2][4];
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