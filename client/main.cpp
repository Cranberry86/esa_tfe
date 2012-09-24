#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "UDPNetwork.h"
#include "Widget.h"
#include "TextInput.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    UDPNetwork network;
    network.launch();
    
    sf::RenderWindow app(sf::VideoMode(300, 100, 32), "Client");
    
    
    TextInput input;
    input.display(app);
    
    
    while(app.IsOpened())
    {
        sf::Event event;
        while(app.GetEvent(event))
        {
            switch(event.Type)
            {
                case sf::Event::Closed:
                    app.Close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.Key.Code)
                    {
                        case sf::Key::Up:
                            std::cout << "KEY UP PRESSED" << std::endl;
                            network.sendData();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        
        
        app.Clear();
        input.display(app);
        app.Display();
    }
    return 0;
}

