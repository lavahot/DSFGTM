#ifndef JOB_H
#define JOB_H


class Job
{
    public:
        enum proType {IO, CPU};
	private:
		double spawntime;
		int id;
		int processTime;
		int waitTime;
		int cpuQueueTime;
		proType prot;
	public:
		Job(double spawn, int idNew, int proTime, proType type);
		~Job();
		int getType();
		void endWaitq(int qtime);
		void endCPUq(int qtime);
		bool process();
  
};

	Job::Job(double spawn, int idNew, int proTime, proType type)
	{
		spawntime=spawn;
		id=idNew;
		processTime=proTime;
		prot=type;
	}
	Job::~Job()
	{
	}	
	void Job::endWaitq(int qtime)
	{
		waitTime=qtime-spawntime;
		spawntime=0;
	}
	void Job::endCPUq(int qtime)
	{
		cpuQueueTime=qtime-spawntime;
	}
	int Job::getType()
		{
			return prot;
		}
	bool Job::process()
		{//decrements process time counter, returns bool indicating whether there is time left
			if(prot)
				processTime-=2;//if CPU-bound, decrement 2
			else
				processTime--;//if IO bound, decrement 1
			if (!processTime)
				return false;
			else
				return true;
		}
#endif