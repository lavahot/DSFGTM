#ifndef JOB_H
#define JOB_H

enum proType {IO_T, CPU_T};

class Job
{
	private:
		double spawntime;
		int ID;
		int processTime;          //total process time assigned to job
        int processTimeRemaining; //process time remaining
		double waitTime;             //total time in wait queue
		int cpuQueueTime;         //total time in cpu queue
        int cpuStartTime;         //timestamp of cpu queue entry
		proType prot;             //type identifier
	public:
        Job(double spawn, int idNew, int proTime, int type);
		~Job();
		proType getType();
        int getProcTime();
        double getWait();
        int getCPU();
		void endWaitq(int qtime);
		void endCPUq(int qtime);
		bool process();
  
};


#endif
