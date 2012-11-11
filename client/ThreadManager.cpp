#include <SFML/System/Unix/Thread.hpp>
#include <SFML/Graphics/Image.hpp>
#include <map>

#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::ThreadManager(Game* game)
{
    this->game = game;
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
    
//    sf::Context context;
//    context.SetActive(true);
    
    for(std::multimap<int, std::string>::iterator it = this->to_load.begin(); it != this->to_load.end(); ++it)
    {
        if(it->first == 1) // image
        {
            game->getImageManager()->loadImage(it->second);
        }
        else if(it->first == 2) // son
        {
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