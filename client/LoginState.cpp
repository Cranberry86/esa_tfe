/* 
 * File:   LoginState.cpp
 * Author: cranberry
 * 
 * Created on 6 octobre 2012, 17:07
 */

#include "LoginState.h"

void LoginState::init(Game* game, UDPNetwork* network)
{
    interface.setImageManager(game->getImageManager());
    interface.setNetwork(network);
    
    loading_screen = new LoadingState();
    std::multimap<int, std::string> to_load;
    to_load.insert(std::pair<int, std::string>(1, "/home/cranberry/www/esa_tfe/client/images/bg.jpg"));
    to_load.insert(std::pair<int, std::string>(2, "/home/cranberry/www/esa_tfe/client/images/bg.jpg"));
    to_load.insert(std::pair<int, std::string>(2, "/home/cranberry/www/esa_tfe/client/images/bg2.jpg"));
    loading_screen->toLoad(to_load);
    game->pushShate(loading_screen);
        
    this->network = network;
    this->observer = new ButtonObserver();
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
//                        this->network->sendData();
                        break;
                }
                break;
            default:
                break;
        }
        this->interface.handleEvents(event);
    }
}

void LoginState::pause()
{
}

void LoginState::resume()
{
    // TODO : USE THE IMAGE MANAGERS
    interface.addBackground("/home/cranberry/www/esa_tfe/client/images/bg.jpg");
     
    interface.addTextInput("login_input", sf::Vector2f(50,0), sf::Vector2f(100,20), sf::Color::Green, 1, sf::Color::Yellow);
    interface.getTextInput("login_input")->setMaxLength(14);
    interface.getTextInput("login_input")->setTextColor(sf::Color::Black);
    interface.getTextInput("login_input")->setTextSize(22);
    
    interface.addTextInput("pwd_input", sf::Vector2f(200,0), sf::Vector2f(100,20), sf::Color::Yellow, 1, sf::Color::Yellow);
    interface.getTextInput("pwd_input")->setMaxLength(14);
    interface.getTextInput("pwd_input")->setTextColor(sf::Color::Black);
    interface.getTextInput("pwd_input")->setTextSize(22);
    
    interface.addAfter("login_input", "pwd_input");
    
//    interface.addTextInput("truc", sf::Vector2f(400,0), sf::Vector2f(100,20), sf::Color::Red, 1, sf::Color::Yellow);
//    interface.getTextInput("truc")->setMaxLength(14);
//    interface.getTextInput("truc")->setTextColor(sf::Color::Black);
//    interface.getTextInput("truc")->setTextSize(22);
//    
//    interface.addAfter("login_input", "truc");
    
    interface.addButton("ok_button", sf::Vector2f(200,200), sf::Vector2f(100,20), sf::Color::Blue, 1, sf::Color::Black);
    interface.getWidget("ok_button")->setText("Login");
    interface.getWidget("ok_button")->setTextColor(sf::Color::Black);
    interface.getWidget("ok_button")->setTextSize(22);
    interface.getButton("ok_button")->AddObserver(this->observer);
    
    interface.addRoundedBackground("bg_inputs", sf::Vector2f(10,10), sf::Vector2f(500,500), 10, 10, sf::Color(0, 255, 255, 128), 1, sf::Color::Black);
        
    interface.addLabel("label_login", "Username :", 50, sf::Color::Black, sf::Vector2f(0,300));
    
    interface.addLabel("label_error", "Username or password incorrect", 50, sf::Color::White, sf::Vector2f(10,50));
    interface.getWidget("label_error")->setVisible(false);
}

void LoginState::update(Game* game)
{
    if(this->observer->getButtonName() == "ok_button")
    {
        std::cout << "greeeeuh euhe euh" << std::endl;
    }
}