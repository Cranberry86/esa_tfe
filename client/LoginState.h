/* 
 * File:   LoginState.h
 * Author: cranberry
 *
 * Created on 6 octobre 2012, 17:07
 */

#ifndef LOGINSTATE_H
#define	LOGINSTATE_H

#include "GameState.h"
#include "Interface.h"
#include "LoadingState.h"
#include "ButtonObserver.h"
#include <iostream>


class LoginState : public GameState {
public:
    void init(Game* game, UDPNetwork* network);
    void draw(sf::RenderWindow* window);
    void handleEvents(Game* game);
    void pause();
    void resume();
    void update(Game* game);
private:
    Interface interface;
    sf::RenderWindow* window;
    UDPNetwork* network;
    LoadingState* loading_screen;
    ButtonObserver* observer;
};

#endif	/* LOGINSTATE_H */

