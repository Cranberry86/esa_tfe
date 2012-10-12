#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "UDPNetwork.h"
#include "Widget.h"
#include "TextInput.h"
#include "Button.h"
#include "Game.h"

#include "LoginState.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    UDPNetwork network;
    network.launch();
    
    Game game;
    game.init(900,600,"TFE - Client");
    
    LoginState login_state;
    game.pushShate(&login_state);
    
    while(game.isRunning())
    {
        game.draw();
    }
    
//    sf::RenderWindow app(sf::VideoMode(300, 100, 32), "Client");
    
    
//    TextInput input(sf::Vector2f(100,20), sf::Color::White, 1, sf::Color::Magenta);
//    input.setPosition(sf::Vector2f(10,10));
//    
//    Button btn(sf::Vector2f(200, 20), sf::Color::Cyan, 0);
//    btn.setPosition(sf::Vector2f(50,50));
//    
//    while(app.IsOpened())
//    {
//        sf::Event event;
//        while(app.GetEvent(event))
//        {
//            switch(event.Type)
//            {
//                case sf::Event::Closed:
//                    app.Close();
//                    break;
//                case sf::Event::KeyPressed:
//                    switch(event.Key.Code)
//                    {
//                        case sf::Key::Up:
//                            std::cout << "KEY UP PRESSED" << std::endl;
//                            network.sendData();
//                            break;
//                        default:
//                            break;
//                    }
//                    break;
//                default:
//                    break;
//            }
//        }
//        
//        
//        app.Clear();
//        input.display(app);
//        btn.display(app);
//        app.Display();
//    }
    return 0;
}

