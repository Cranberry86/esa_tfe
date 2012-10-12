/* 
 * File:   Game.cpp
 * Author: cranberry
 * 
 * Created on 5 octobre 2012, 19:44
 */

#include <SFML/Window/Window.hpp>

#include "Game.h"

Game::Game()
{
}

Game::Game(const Game& orig)
{
}

Game::~Game()
{
}

void Game::init(int width, int height, std::string title)
{
    this->window.Create(sf::VideoMode(width, height, 32), title);
    this->window.SetFramerateLimit(60);
    this->running = true;
}

void Game::changeState(GameState* state)
{
    this->states.push_back(state);
}

void Game::popState()
{
    this->states.pop_back();
}

void Game::pushShate(GameState* state)
{
    std::cout << "game::pushstate" << std::endl;
    this->states.push_back(state);
    this->states.back()->init();
}

bool Game::isRunning()
{
    return this->running;
}

void Game::draw()
{
//    std::cout << "game::draw" << std::endl;
    this->window.Clear(sf::Color::White);
    this->states.back()->draw(&this->window);
    this->window.Display();
}