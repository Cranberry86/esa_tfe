/* 
 * File:   GameState.h
 * Author: cranberry
 *
 * Created on 5 octobre 2012, 19:47
 */

#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "Game.h"

class GameState {
public:
    virtual void draw(sf::RenderWindow* window) = 0;
    virtual void init(Game* game, UDPNetwork* network) = 0;
    virtual void handleEvents(Game* game) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void update(Game* game) = 0;
private:

};

#endif	/* GAMESTATE_H */

