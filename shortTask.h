#pragma once

#include "taskAllocator.h"

class ShortTask : public virtual TaskAllocator
{

public:

	ShortTask() { i_quickCounter = 0, i_quickTarget = 0; }

	ShortTask(int parameter);

	int setTask() override;

	
	
	void getThread() override;

	void lockGuardOne();

	void lockGuardTwo();

	void threadJoiner() override;

	void getLockThread();

	void getLockThreadTwo();

private:


	int i_quickCounter;

	int i_quickTarget;

	std::vector<int> i_vector;
	
	std::thread threadOne;
	std::thread threadTwo;
	std::thread threadThree;

	std::mutex mtx;



};