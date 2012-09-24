#include <SFML/System/Unix/Thread.hpp>

#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::ThreadManager(const ThreadManager& orig)
{
}

ThreadManager::~ThreadManager()
{
}

void ThreadManager::start()
{
    this->Launch();
}

void ThreadManager::Run()
{
    running = true;
    for (int i = 0; i < 1000; ++i)
            std::cout << "I'm the thread number 2" << std::endl;
    running = false;
}

bool ThreadManager::isRunning()
{
    return running;
}

void ThreadManager::stop()
{
    this->Wait();
}

void ThreadManager::forceStop()
{
    this->Terminate();
}