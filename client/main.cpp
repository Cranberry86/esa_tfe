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
//    UDPNetwork network;
//    network.launch();
    
    Game game;
    game.init(800,600,"TFE - Client");
    
    LoginState login_state;
    game.pushShate(&login_state);
    
    while(game.isRunning())
    {
        game.handleEvents();
        if(game.getNetwork()->isAwaitingAnswer())
                game.getNetwork()->receiveData();
        game.draw();
    }
    return 0;
}

