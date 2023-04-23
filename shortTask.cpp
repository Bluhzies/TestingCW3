#include "shortTask.h"

ShortTask::ShortTask(int parameter)
{

	i_quickCounter = 0;

	i_quickTarget = parameter;

}

int ShortTask::setTask()
{

	//std::lock_guard<std::mutex> guard(mtx);
		
		while (i_quickCounter < i_quickTarget) {
			std::cout << "The short task counter is currently at: " << i_quickCounter << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			i_quickCounter++;
		}
	
		return i_quickCounter;
		

}


void ShortTask::lockGuardOne()
{

	std::lock_guard<std::mutex> guard(mtx);

	int i = 0;
	while (i < 30)
	{

		std::cout << "Process this" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		++i;
		i_vector.push_back(i);

	}

}

void ShortTask::lockGuardTwo()
{

	std::lock_guard<std::mutex> guard(mtx);

	int j = 0;
	if (i_vector.size() < 50)
	{

		while (j < 50)
		{

			std::cout << "Process this second thing" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			++j;
			i_vector.push_back(j);
		}

	}

}

void ShortTask::getThread()
{



	threadOne = std::thread([&] { setTask(); });



}



void ShortTask::getLockThread()
{

	threadTwo = std::thread([&] { lockGuardOne(); });

}

void ShortTask::getLockThreadTwo()
{

	threadThree = std::thread([&] { lockGuardTwo(); });

}

void ShortTask::threadJoiner()
{

	threadOne.join();
	threadTwo.join();
	threadThree.join();

}




