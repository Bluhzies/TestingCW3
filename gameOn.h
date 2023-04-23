#pragma once

#include "player.h"
#include "taskAllocator.h"

class GameOn : public virtual TaskAllocator
{

public:

	GameOn() {};

	void startTheGame();

	void getThread();

	void threadJoiner() override;

private:

	std::thread gameThread;

};