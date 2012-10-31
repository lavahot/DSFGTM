#ifndef JOB_H
#define JOB_H

enum proType {IO_T, CPU_T};

class Job
{
	private:
		int spawntime;
		int ID;
		int processTime;          //total process time assigned to job
        int processTimeRemaining; //process time remaining
		int waitTime;             //total time in wait queue
		int cpuQueueTime;         //total time in cpu queue
        int cpuStartTime;         //timestamp of cpu queue entry
		proType prot;             //type identifier
	public:
        Job(int spawn, int idNew, int proTime, int type);
		~Job();
		proType getType();
        int getProcTime();
        int getStartTime();
        int getWait();
        int getCPU();
		void endWaitq(int qtime);
		void endCPUq(int qtime);
		bool process();
        int getID();
  
};


#endif
