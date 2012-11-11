/* 
 * File:   Game.cpp
 * Author: cranberry
 * 
 * Created on 5 octobre 2012, 19:44
 */

#include <SFML/Window/Window.hpp>

#include "Game.h"
#include "GameState.h"
//class GameState;

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
    network.launch();
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
    {
        this->states.pop_back();
    }
    this->states.push_back(state);
    this->states.back()->init(this, &this->network);
}

void Game::popState()
{
    this->states.pop_back();
    this->states.back()->resume();
    std::cout << "game::popstate" << std::endl;
}

void Game::pushShate(GameState* state)
{
    std::cout << "game::pushstate" << std::endl;
    this->states.back()->pause();
    std::cout << "gamestate::pause" << std::endl;
    this->states.push_back(state);
    this->states.back()->init(this, &this->network);
    std::cout << "game::pushstate end" << std::endl;
}

bool Game::isRunning()
{
    return this->running;
}

void Game::draw()
{
    this->window.Clear(sf::Color::White);
    this->states.back()->draw(&this->window);
    this->window.Display();
}

void Game::handleEvents()
{
    this->states.back()->handleEvents(this);
}

void Game::quit()
{
    this->running = false;
    this->window.Close();
}

sf::RenderWindow* Game::getWindow()
{
    return &this->window;
}

UDPNetwork* Game::getNetwork()
{
    return &this->network;
}

ImageManager* Game::getImageManager()
{
    return &this->imanager;
}