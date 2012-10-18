/* 
 * File:   LoginState.cpp
 * Author: cranberry
 * 
 * Created on 6 octobre 2012, 17:07
 */

#include "LoginState.h"

void LoginState::init(UDPNetwork* network)
{
    interface.addTextInput("login_input", sf::Vector2f(100,20), sf::Color::Green, 1, sf::Color::Magenta);
    interface.getWidget("login_input")->SetPosition(sf::Vector2f(10,10));
    interface.addButton("ok_button", sf::Vector2f(100,20), sf::Color::Red, 1, sf::Color::Black);
    interface.getWidget("ok_button")->SetPosition(sf::Vector2f(100,150));
    
    interface.addBackground("/home/cranberry/www/esa_tfe/client/images/bg2.jpg");
    
    this->network = network;
}

void LoginState::draw(sf::RenderWindow* window)
{
    this->interface.displayWidgets(window);
}

void LoginState::handleEvents(Game* game)
{
    sf::RenderWindow* window = game->getWindow();
    sf::Event event;
    while(window->GetEvent(event))
    {
        switch(event.Type)
        {
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                switch(event.Key.Code)
                {
                    case sf::Key::Up:
                        this->network->sendData();
                        break;
                }
                break;
            default:
                break;
        }
    }
}