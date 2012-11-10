#include <SFML/System/Unix/Thread.hpp>
#include <SFML/Graphics/Image.hpp>
#include <map>

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
    
    for(std::multimap<int, std::string>::iterator it = this->to_load.begin(); it != this->to_load.end(); ++it)
    {
        std::cout << "element" << std::endl;
        if(it->first == 1) // image
        {
            std::cout << "image" << std::endl;
            sf::Image img;
            if(!img.LoadFromFile(it->second))
            {
                std::cout << "ERROR LOADING IMAGE" << std::endl;
            }
            else
            {
                std::cout << "OK LOADING IMAGE" << std::endl;
            }
        }
        else if(it->first == 2) // son
        {
            std::cout << "son" << std::endl;
            sf::SoundBuffer Buffer;
            // only to have a high loading time
            if (!Buffer.LoadFromFile("/home/cranberry/www/esa_tfe/client/musics/1.flac"))
            {
                std::cout << "ERROR LOADING MUSIC" << std::endl;
            }
            else
            {
                std::cout << "OK LOADING MUSIC" << std::endl;
            }
        }
    }
    
    std::cout << "after for" << std::endl;
    
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

void ThreadManager::toLoad(std::multimap<int,std::string> to_load)
{
    this->to_load = to_load;
}