/* 
 * File:   Game.h
 * Author: cranberry
 *
 * Created on 5 octobre 2012, 19:44
 */

#ifndef GAME_H
#define	GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class GameState;

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
    void handleEvents();
    void quit();
    sf::RenderWindow* getWindow();
private:
    std::vector<GameState*> states;
    sf::RenderWindow window;
    bool running;
};

#endif	/* GAME_H */

