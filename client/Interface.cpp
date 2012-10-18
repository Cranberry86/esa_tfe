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
    window->Draw(this->bg);
}

void Interface::registerButton(Button& btn)
{
    this->buttons[btn.getName()] = btn;
    this->widgets[btn.getName()] = &this->buttons[btn.getName()];
}

void Interface::registerTextInput(TextInput& input)
{
    this->textinputs[input.getName()] = input;
    this->widgets[input.getName()] = &this->textinputs[input.getName()];
}

void Interface::addBackground(std::string filename)
{
    BackgroundImage bg(filename);
    this->bg = bg;
    this->bg.setSpriteFromImage();
}

void Interface::addButton(std::string name, sf::Vector2f size, sf::Color back, int border_size, sf::Color border)
{
    Button btn(size, back, border_size, border);
    btn.setName(name);
    registerButton(btn);
}

void Interface::addTextInput(std::string name, sf::Vector2f size, sf::Color back, int border_size, sf::Color border)
{
    TextInput ti(size, back, border_size, border);
    ti.setName(name);
    registerTextInput(ti);
}

Widget* Interface::getWidget(std::string name)
{
    return this->widgets[name];
}