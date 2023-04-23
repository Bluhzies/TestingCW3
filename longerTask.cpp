#include "longerTask.h"

LongerTask::LongerTask(int parameter)
{

	i_longerCounter = 0;

	i_longerTarget = parameter;

}

int LongerTask::setTask()
{
	
	std::lock_guard<std::mutex> guard(mtx);

	while (i_longerCounter < i_longerTarget) {
		std::cout << "The longer task counter is currently at: " << i_longerCounter << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		i_longerCounter++;
	}

	return i_longerCounter;

}

void LongerTask::getThread()
{

	

	

	threadTwo = std::thread([&] { setTask(); });
	


}

void LongerTask::threadJoiner()
{

	threadTwo.join();

	
	
}


