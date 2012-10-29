#ifndef CLOCK
#define CLOCK
class Clock
{
	private:
		double time;
	public:
		Clock()
		{
			time=0;
		}
		void advTime()
		{
			time++;	
		}
		double getTime()
		{
			return time;
		}
};

#endif