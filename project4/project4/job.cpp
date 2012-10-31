//
//  job.cpp
//  project4
//
//  Created by Taylor Mansfield on 10/30/12.
//  Copyright (c) 2012 Taylor Mansfield. All rights reserved.
//

#include "job.h"

//Job::Job(double spawn, int idNew, int proTime, proType type)
//{
//	spawntime=spawn;
//	ID=idNew;
//	processTime=proTime;
//    processTimeRemaining=processTime;
//	prot=type;
//    cpuQueueTime=0;
//    cpuStartTime=0;
//}

Job::Job(double spawn, int idNew, int proTime, int type)
{
    spawntime=spawn;
    ID=idNew;
    processTime=proTime;
    processTimeRemaining=processTime;
    if (type) {
        prot=CPU_T;
    }
    else
    {
        prot=IO_T;
    }
    cpuQueueTime=0;
    cpuStartTime=0;
}
Job::~Job()
{
}
void Job::endWaitq(int qtime)
{
    waitTime=qtime-spawntime;
    cpuStartTime=qtime;
}
void Job::endCPUq(int qtime)
{
    cpuQueueTime=qtime-cpuStartTime;
}
proType Job::getType()
{
    return prot;
}
bool Job::process()
{//decrements process time counter, returns bool indicating whether there is time left
    if(prot)
        processTimeRemaining-=2;//if CPU-bound, decrement 2
    else
        processTimeRemaining--;//if IO bound, decrement 1
    if (!processTimeRemaining)
        return false;
    else
        return true;
}
int Job::getProcTime()
{
    return processTime;
}

double Job::getWait()
{
    return waitTime;
}
int Job::getCPU()
{
    return cpuQueueTime;
}