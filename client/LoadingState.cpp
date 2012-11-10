/* 
 * File:   LoadingState.cpp
 * Author: cranberry
 * 
 * Created on 28 octobre 2012, 17:43
 */

#include "LoadingState.h"

void LoadingState::init(Game* game, UDPNetwork* network)
{
    thread = new ThreadManager();
    thread->toLoad(this->to_load);
    thread->Launch();
    this->game = game;
}

void LoadingState::draw(sf::RenderWindow* window)
{
    sf::String s;
    s.SetText("LOADING SCREEN");
    s.SetSize(50);
    s.SetColor(sf::Color::Black);
    s.SetFont(sf::Font::GetDefaultFont());
    window->Draw(s);
    
    if(!thread->isRunning())
    {
        this->game->popState();
    }
}

void LoadingState::handleEvents(Game* game)
{
}

void LoadingState::pause()
{
    
}

void LoadingState::resume()
{
    
}

void LoadingState::toLoad(std::multimap<int,std::string> to_load)
{
    this->to_load = to_load;
}