//
//  cpu.cpp
//  project4
//
//  Created by Taylor Mansfield on 10/30/12.
//  Copyright (c) 2012 Taylor Mansfield. All rights reserved.
//

#include "cpu.h"

CPU::CPU()
{
    jobQue= new QueList<Job*> (5);
    idletime=0.0;
}
CPU::CPU(int newID, StatModule *stat)
{//use this constructor for our purposes.
    jobQue= new QueList<Job*> (5);
    statM=stat;
    ID=newID;
    idletime=0.0;
}
CPU::~CPU()
{
    jobQue->MakeEmpty();
    delete jobQue;
}
int CPU::process(int ctime)
{
    jobtime=1;
    Job *jobTmp;
    if (!jobQue->IsEmpty())
    {
        queLength=jobQue->GetLength();
        for(int i = 0; i<queLength; i++)
        {
            jobQue->Dequeue(jobTmp);
            if(jobTmp->process())
            {
                jobQue->Enqueue(jobTmp);
                if(jobTmp->getType())
                    //is CPU type
                    idletime-=0.2;
                else
                    //is IO type
                    idletime-=0.1;
            }
            else
            {
                jobTmp->endCPUq(ctime);
                statM->reportJobEnd(jobTmp);
                
                delete jobTmp;
            }
        }
    }
    return idletime;
    
}
bool CPU::enQ(Job *jobitem)
{
    if (!jobQue->IsFull())
    {
        jobQue->Enqueue(jobitem);
        return true;//job queue has room, item enqueued.
    }
    else
        return false;//queue is full, try later.
}
bool CPU::IsFull()
{
    return jobQue->IsFull();
}
