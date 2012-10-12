/* 
 * File:   Game.h
 * Author: cranberry
 *
 * Created on 5 octobre 2012, 19:44
 */

#ifndef GAME_H
#define	GAME_H

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Game {
public:
    Game();
    Game(int width, int height, std::string title);
    Game(const Game& orig);
    virtual ~Game();
    void init(int width, int height, std::string title);
    void changeState(GameState* state);
    void pushShate(GameState* state);
    void popState();
    bool isRunning();
    void draw();
private:
    std::vector<GameState*> states;
    sf::RenderWindow window;
    bool running;
};

#endif	/* GAME_H */

