/* 
 * File:   LoadingState.cpp
 * Author: cranberry
 * 
 * Created on 28 octobre 2012, 17:43
 */

#include "LoadingState.h"

void LoadingState::init(Game* game, UDPNetwork* network)
{
    thread = new ThreadManager(game);
    thread->toLoad(this->to_load);
    thread->Launch();
    this->game = game;
    
    this->sprite = new AnimatedSprite(0.1f);
    this->animation = new Animation();
    sf::Image& img = this->game->getImageManager()->getImage("/home/cranberry/www/esa_tfe/client/images/spritesheet.png");
    this->animation->pushFrame(img, sf::IntRect(40,0,60,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(60,0,80,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(80,0,100,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(100,0,120,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(120,0,140,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(140,0,160,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(160,0,180,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(180,0,200,28), sf::Color(173, 231,24));
    this->animation->pushFrame(img, sf::IntRect(200,0,220,28), sf::Color(173, 231,24));
    this->sprite->setAnimation(this->animation);
    this->sprite->setFrameTime(0.1f);
    this->sprite->SetPosition(100, 100);
    // todo : delete them !
}

void LoadingState::draw(sf::RenderWindow* window)
{
    sf::String s;
    s.SetText("LOADING SCREEN");
    s.SetSize(50);
    s.SetColor(sf::Color::Black);
    s.SetFont(sf::Font::GetDefaultFont());
    window->Draw(s);
    this->sprite->play(window->GetFrameTime());
    window->Draw(*this->sprite);
    
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

void LoadingState::update(Game* game)
{
    
}