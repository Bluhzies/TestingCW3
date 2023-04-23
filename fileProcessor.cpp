#include "fileProcessor.h"

FileProcessor::FileProcessor(std::string s_fileOne, std::string s_fileTwo)
{

	sFileIn = s_fileOne;

	sFileOut = s_fileTwo;

}

bool FileProcessor::processFile()
{

	std::cout << "Beginning file processing" << std::endl;
	std::ifstream in(sFileIn);
	std::vector<std::vector<std::string>> vsFields;

	std::ofstream outputFile;
	outputFile.open(sFileOut, std::ofstream::out | std::ofstream::trunc);

	if (in)
	{

		std::string sLine;

		while (getline(in, sLine))
		{

			std::stringstream sep(sLine);
			std::string sField;

			vsFields.push_back(std::vector<std::string>());

			while (getline(sep, sField, ',')) {
				vsFields.front().push_back(sField);
			}

		}

	}

	if (outputFile.is_open())
	{

		for (auto row : vsFields)
		{
			for (auto field : row)
			{
				outputFile << field << "," << std::endl;
			}
		}

	}
	std::cout << "\nProcess is complete" << std::endl;

	return true;
}


void FileProcessor::getThread()
{

	threadThree = std::thread([&] { processFile(); });

}

void FileProcessor::threadJoiner()
{

	threadThree.join();

}


