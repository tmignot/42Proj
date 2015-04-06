#ifndef TIMER_HPP
#define TIMER_HPP

#include <sys/time.h>
#include <unistd.h>
#include <thread>
#include <chrono>

class Timer {

	public :

		typedef std::chrono::high_resolution_clock::time_point	TimePoint;

	private	:

		unsigned int	Framerate;
		TimePoint			CreatedAt;
		TimePoint			StartedAt;
		TimePoint			EndedAt;

	public	:

		Timer();
		Timer(unsigned int);
		Timer(Timer const&);
		~Timer();

		Timer& operator=(Timer const&);

		unsigned int		GetFramerate() const;
		TimePoint				GetCreationTime() const;
		TimePoint				GetStart() const;
		TimePoint				GetEnd() const;

		void				SetFramerate(unsigned int);

		void				Start();
		void				Stop();
		void				Wait();
		unsigned long int	ElapsedTime();
};

#endif
