#ifndef THREADMANAGER_H
#define	THREADMANAGER_H

#include <iostream>
#include <SFML/Audio.hpp>

class ThreadManager : public sf::Thread {
public:
    ThreadManager();
    ThreadManager(const ThreadManager& orig);
    virtual ~ThreadManager();
    void start();
    bool isRunning();
    void stop();
    void forceStop();
private:
    bool running;
    virtual void Run();
};

#endif	/* THREADMANAGER_H */

