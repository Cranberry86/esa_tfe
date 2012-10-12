/* 
 * File:   Interface.cpp
 * Author: cranberry
 * 
 * Created on 6 octobre 2012, 21:27
 */

#include <vector>

#include "Interface.h"

Interface::Interface()
{
}

Interface::Interface(const Interface& orig)
{
}

Interface::~Interface()
{
    
}

void Interface::init()
{
    
}

void Interface::displayWidgets(sf::RenderWindow* window)
{
    for(std::map<std::string, Widget*>::iterator it = this->widgets.begin(); it != this->widgets.end(); ++it)
    {
        window->Draw(*it->second);
    }
}

void Interface::addButton(Button& btn)
{
    this->buttons[btn.getName()] = btn;
    this->widgets[btn.getName()] = &this->buttons[btn.getName()];
}

void Interface::addTextInput(TextInput& input)
{
    this->textinputs[input.getName()] = input;
    this->widgets[input.getName()] = &this->textinputs[input.getName()];
}

void Interface::addBackgrounds(BackgroundImage& bg)
{
    this->backgrounds[bg.getName()] = bg;
    this->bg = bg;
}