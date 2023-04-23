#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <future>
#include <stdio.h>
#include <vector>
#include <mutex>

class TaskAllocator 
{

public:

	virtual void getThread() {};
	
	virtual int setTask() { return 0; }

	virtual void threadJoiner() {};

private:


};