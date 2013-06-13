#include "Timer.h"

Timer::Timer()
{
	FrameTime = 0.0f;
}
Timer::~Timer()
{

}

void Timer::Init()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&Frequency);
	TicksPerMs = (float) Frequency/1000;
	QueryPerformanceCounter((LARGE_INTEGER*)&StartTime);
}
void Timer::Frame()
{
	INT64 currentTime;
	float timeDiff;

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	timeDiff = (float)(currentTime - StartTime);
	FrameTime = timeDiff / TicksPerMs;
	StartTime = currentTime;
}
float Timer::GetTime()
{
	return .016f;
}
