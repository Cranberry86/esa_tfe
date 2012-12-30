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

#include "UDPNetwork.h"
#include "ImageManager.h"

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
    void update();
    sf::RenderWindow* getWindow();
    UDPNetwork* getNetwork();
    ImageManager* getImageManager();
private:
    std::vector<GameState*> states;
    sf::RenderWindow window;
    bool running;
    
    UDPNetwork network;
    ImageManager imanager;
};

#endif	/* GAME_H */

