#ifndef TIMER_H
#define TIMER_H
#include <Windows.h>

class Timer
{
public:
	Timer();
	~Timer();
	void Init();
	void Frame();
	float GetTime();
private:
	INT64 Frequency;
	float TicksPerMs;
	INT64 StartTime;
	float FrameTime;
};
#endif