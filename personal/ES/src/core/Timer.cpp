#include "core/Timer.hpp"

Timer::Timer()
	: Framerate(0)
{
	CreatedAt = std::chrono::high_resolution_clock::now();
}

Timer::Timer(unsigned int framerate)
	: Framerate(framerate)
{
	CreatedAt = std::chrono::high_resolution_clock::now();
}

Timer::Timer(Timer const& copy)
{
	*this = copy;
}

Timer::~Timer() {}

Timer& Timer::operator=(Timer const& rhs)
{
	CreatedAt = rhs.GetCreationTime();
	Framerate = rhs.GetFramerate();
	StartedAt = rhs.GetStart();
	EndedAt = rhs.GetEnd();
	return *this;
}

unsigned int			Timer::GetFramerate() const			{ return Framerate;	}
Timer::TimePoint	Timer::GetCreationTime() const	{ return CreatedAt;	}
Timer::TimePoint	Timer::GetStart() const					{ return StartedAt;	}
Timer::TimePoint	Timer::GetEnd() const						{ return EndedAt;		}

void	Timer::SetFramerate(unsigned int framerate)
{
	Framerate = framerate;
}

void	Timer::Start()
{
	StartedAt = std::chrono::high_resolution_clock::now();
}

void	Timer::Stop()
{
	EndedAt = std::chrono::high_resolution_clock::now();
}

void	Timer::Wait()
{
	std::chrono::duration<long int, std::nano> diff = StartedAt - EndedAt;

	long int nSecPerFrame = 1000000000.f / Framerate;

	if (diff.count() < nSecPerFrame)
		std::this_thread::sleep_for(std::chrono::nanoseconds(nSecPerFrame - diff.count()));
}

unsigned long int	Timer::ElapsedTime()
{
	TimePoint now = std::chrono::high_resolution_clock::now();

	std::chrono::duration<long int, std::nano> diff = StartedAt - now;

	return (diff.count());
}
