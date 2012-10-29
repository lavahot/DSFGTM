#ifndef JOB_H
#define JOB_H

enum proType {IO, CPU};

class Job
{
	private:
		double spawntime;
		int ID;
		int processTime;          //total process time assigned to job
        int processTimeRemaining; //process time remaining
		int waitTime;             //total time in wait queue
		int cpuQueueTime;         //total time in cpu queue
        int cpuStartTime;         //timestamp of cpu queue entry
		proType prot;             //type identifier
	public:
		Job(double spawn, int idNew, int proTime, proType type);
		~Job();
		proType getType();
        int getProcTime();
        int getWait();
        int getCPU();
		void endWaitq(int qtime);
		void endCPUq(int qtime);
		bool process();
  
};

	Job::Job(double spawn, int idNew, int proTime, proType type)
	{
		spawntime=spawn;
		ID=idNew;
		processTime=proTime;
        processTimeRemaining=processTime;
		prot=type;
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

int Job::getWait()
{
    return waitTime;
}
int Job::getCPU()
{
    return cpuQueueTime;
}
#endif