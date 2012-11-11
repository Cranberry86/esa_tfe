#ifndef THREADMANAGER_H
#define	THREADMANAGER_H

#include <iostream>
#include <SFML/Audio.hpp>

#include "Game.h"

class ThreadManager : public sf::Thread {
public:
    ThreadManager();
    ThreadManager(Game* game);
    ThreadManager(const ThreadManager& orig);
    virtual ~ThreadManager();
    void start();
    bool isRunning();
    void stop();
    void forceStop();
    void toLoad(std::multimap<int, std::string> to_load);
private:
    bool running;
    virtual void Run();
    std::multimap<int, std::string> to_load;
    Game* game;
};

#endif	/* THREADMANAGER_H */

