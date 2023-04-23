#pragma once

#include "taskAllocator.h"

class FileProcessor : public virtual TaskAllocator
{


public:

	FileProcessor() {};

	FileProcessor(std::string sFileIn, std::string sFileOut);

	bool processFile();

	void getThread() override;

	void threadJoiner() override;

private:

	std::string sFileIn;

	std::string sFileOut;

	std::thread threadThree;

};