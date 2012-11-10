/* 
 * File:   LoadingState.h
 * Author: cranberry
 *
 * Created on 28 octobre 2012, 17:43
 */

#ifndef LOADINGSTATE_H
#define	LOADINGSTATE_H

#include "GameState.h"
#include "ThreadManager.h"


class LoadingState : public GameState {
public:
    void init(Game* game, UDPNetwork* network);
    void draw(sf::RenderWindow* window);
    void handleEvents(Game* game);
    void pause();
    void resume();
private:
    ThreadManager* thread;
    Game* game;
};

#endif	/* LOADINGSTATE_H */

