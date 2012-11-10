#include <SFML/System/Unix/Thread.hpp>
#include <SFML/Graphics/Image.hpp>

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
    sf::SoundBuffer Buffer;
    // only to have a high loading time
    if (!Buffer.LoadFromFile("/home/cranberry/www/esa_tfe/client/musics/1.flac"))
    {
        std::cout << "ERROR LOADING MUSIC" << std::endl;
    }
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