#ifndef STATMODULE
#define STATMODULE

#include "job.h"
#include <fstream>

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
        void printStatus();
};

StatModule::StatModule()
{
    //initialize cpu idle array
    for(int i =0; i<10; i++)
    {
        CPUIdle[i]=0;
    }
    //initialize stat array
    for(int i=0;i<2;i++)
    {
        for(int j = 0; j<4; j++)
        {
            jobStatArry[i][j].numOfType=0;
            jobStatArry[i][j].totCPUQ=0;
            jobStatArry[i][j].totWaitQ=0;
        }
    }
}
StatModule::StatModule(std::ofstream &fileo)
{//use this constructor
    fileOut=&fileo;
}
StatModule::~StatModule()
{}
void StatModule::reportJobEnd(Job *job)
{
    proType typeTmp;
    int procTimeTmp;
    typeTmp=job->getType();
    
    switch (job->getProcTime()) {
        case 10:
            procTimeTmp=0;
            break;
        case 20:
            procTimeTmp=1;
            break;
        case 30:
            procTimeTmp=2;
            break;
        case 60:
            procTimeTmp=3;
            break;
        default:
            break;
    }
    
    jobStatArry[typeTmp][procTimeTmp].totCPUQ+=job->getCPU();
    jobStatArry[typeTmp][procTimeTmp].totWaitQ+=job->getWait();
    jobStatArry[typeTmp][procTimeTmp].numOfType++;
    
}

void StatModule::reportCPUIdle(float idleTime, int cpuid)
{
    CPUIdle[cpuid]+=idleTime;
}

void StatModule::printStats()
{//use for final report at simulation completion
    
}

void StatModule::printStatus()
{//use to print periodic stats
    
}

#endif