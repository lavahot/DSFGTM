#IFNDEF STATMODULE
#DEFINE STATMODULE
#IFNDEF JOB
//#DEFINE JOB
#include "job.h"
#ENDIF

#include <fstream>

class StatModule()
{
	private:
		struct stats
		{
			int avgWaitQ;
			int avgCPUQ;
			int numOfType;
			
		}
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

	StatModule::StatModule();
	{}
	StatModule::~StatModule();
	{}
	StatModule::reportJobEnd(Job *job)
	{
	}