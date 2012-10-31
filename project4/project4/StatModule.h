#ifndef STATMODULE
#define STATMODULE

#include "job.h"
#include <fstream>
#include <iomanip>

class StatModule
{
	private:
        std::ofstream *fileOut;
		struct stats
		{
			int totWaitQ;
			int totCPUQ;
			int numOfType;
			
		};
		stats jobStatArry[2][4];
        //array arranged like so:
        //first element determines type e.g. IO=0, CPU=1
        //second element indicates run time requirement
        //[0] 10 sec run time
        //[1] 20 sec run time
        //[2] 30 sec run time
        //[3] 60 sec run time
    
		float CPUIdle[10]; //running total of idle time by CPU
        
	public:
		StatModule();
        StatModule(std::ofstream&);
		~StatModule();
		void reportJobEnd(Job *jobend);
		void reportJobBegin(Job *jobbegin);
		void reportCPUIdle(float, int);
		void printStats();
        void printStatus(int);
};


#endif