#pragma once


#include "taskAllocator.h"
#include <mutex>

class LongerTask : public virtual TaskAllocator
{


public:

	LongerTask() { i_longerCounter = 0, i_longerTarget = 0; }

	LongerTask(int parameter);

	int setTask() override;

	void getThread() override;

	void threadJoiner() override;

	

private:

	int i_longerCounter;

	int i_longerTarget;

	std::thread threadTwo;

	std::mutex mtx;

};