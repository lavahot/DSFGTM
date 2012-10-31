
#include "StatModule.h"
#include "job.h"
#include <fstream>
#include <iomanip>

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

void StatModule::printStatus(int ctime)
{//use to print periodic stats
    *fileOut<<"Current status"<<std::endl;
    *fileOut<<"Number of jobs:"<<std::endl;
    *fileOut<<std::right<<std::setw(20)<<"I/O Type:"<<std::setw(15)<<"CPU Type:"<<std::endl;
    for(int i =0; i<4; i++)
    {
        //rowtemp is the number of seconds for the job
        int rowtemp=0;
        switch (i) {
            case 0:
                rowtemp=10;
                break;
            case 1:
                rowtemp=20;
                break;
            case 2:
                rowtemp=30;
                break;
            case 3:
                rowtemp=60;
                break;
            default:
                break;
        }
        *fileOut<<std::setw(10)<<std::left<<rowtemp<<" sec"<<std::right;
        for(int j =0; j<2; j++)
        {
            *fileOut<<std::setw(10+5*j)<<jobStatArry[j][i].numOfType;
        }
        *fileOut<<std::endl;
        
    }
    *fileOut<<std::endl<<"Average wait queue time of completed jobs:"<<std::endl;
    *fileOut<<std::right<<std::setw(20)<<"I/O Type:"<<std::setw(15)<<"CPU Type:"<<std::endl;
    for(int i =0; i<4; i++)
    {
        int rowtemp=0;
        switch (i) {
            case 0:
                rowtemp=10;
                break;
            case 1:
                rowtemp=20;
                break;
            case 2:
                rowtemp=30;
                break;
            case 3:
                rowtemp=60;
                break;
            default:
                break;
        }
        *fileOut<<std::setw(10)<<std::left<<rowtemp<<" sec"<<std::right;
        for(int j =0; j<2; j++)
        {
            *fileOut<<std::setw(10+5*j)<<jobStatArry[j][i].totWaitQ/jobStatArry[j][i].numOfType;
        }
        *fileOut<<std::endl;
    }
    *fileOut<<std::endl<<"Average CPU queue time of jobs:"<<std::endl;
    *fileOut<<std::right<<std::setw(20)<<"I/O Type:"<<std::setw(15)<<"CPU Type:"<<std::endl;
    for(int i =0; i<4; i++)
    {
        int rowtemp=0;
        switch (i) {
            case 0:
                rowtemp=10;
                break;
            case 1:
                rowtemp=20;
                break;
            case 2:
                rowtemp=30;
                break;
            case 3:
                rowtemp=60;
                break;
            default:
                break;
        }
        *fileOut<<std::setw(10)<<std::left<<rowtemp<<" sec"<<std::right;
        for(int j =0; j<2; j++)
        {
            *fileOut<<std::setw(10+5*j)<<jobStatArry[j][i].numOfType;
        }
        *fileOut<<std::endl;
        
    }
    *fileOut<<std::endl<<std::endl;
    
    
}

