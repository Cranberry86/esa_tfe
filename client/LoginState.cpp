/* 
 * File:   LoginState.cpp
 * Author: cranberry
 * 
 * Created on 6 octobre 2012, 17:07
 */

#include "LoginState.h"

void LoginState::init(UDPNetwork* network)
{
     interface.addBackground("/home/cranberry/www/esa_tfe/client/images/bg.jpg");
     
    interface.addTextInput("login_input", sf::Vector2f(50,0), sf::Vector2f(100,20), sf::Color::Green, 1, sf::Color::Yellow);
    interface.getTextInput("login_input")->setMaxLength(14);
    interface.getTextInput("login_input")->setTextColor(sf::Color::Black);
    interface.getTextInput("login_input")->setTextSize(22);
    
    interface.addButton("ok_button", sf::Vector2f(200,200), sf::Vector2f(100,20), sf::Color::Blue, 1, sf::Color::Black);
    interface.getWidget("ok_button")->setText("Login");
    interface.getWidget("ok_button")->setTextColor(sf::Color::Black);
    interface.getWidget("ok_button")->setTextSize(22);
        
    interface.addLabel("label_login", "Username :", 50, sf::Color::Black, sf::Vector2f(0,300));
    
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
        this->interface.handleEvents(event);
    }
}