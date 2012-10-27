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
    window->Draw(this->bg);
    for (std::map<std::string, Widget*>::iterator it = this->widgets.begin(); it != this->widgets.end(); ++it)
    {
        window->Draw(*it->second);
    }
}

void Interface::registerButton(Button& btn)
{
    this->buttons[btn.getName()] = btn;
    this->buttons[btn.getName()].init();
    this->widgets[btn.getName()] = &this->buttons[btn.getName()];
}

void Interface::registerTextInput(TextInput& input)
{
    this->textinputs[input.getName()] = input;
    this->textinputs[input.getName()].init();
    this->widgets[input.getName()] = &this->textinputs[input.getName()];
}

void Interface::registerLabel(Label& label)
{
    this->labels[label.getName()] = label;
    this->labels[label.getName()].init();
    this->widgets[label.getName()] = &this->labels[label.getName()];
}

void Interface::addBackground(std::string filename)
{
    BackgroundImage bg(filename);
    this->bg = bg;
    this->bg.setSpriteFromImage();
}

void Interface::addButton(std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color bg_color, int border_size, sf::Color border)
{
    Button btn(position, size, bg_color, border_size, border);
    btn.setName(name);
    registerButton(btn);
}

void Interface::addTextInput(std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color bg_color, int border_size, sf::Color border)
{
    TextInput ti(position, size, bg_color, border_size, border);
    ti.setName(name);
    registerTextInput(ti);
}

void Interface::addLabel(std::string name, std::string text, int text_size, sf::Color text_color, sf::Vector2f position)
{
    Label label(text, text_size, text_color, position);
    label.setName(name);
    registerLabel(label);
}

Widget* Interface::getWidget(std::string name)
{
    return this->widgets[name];
}

void Interface::handleEvents(sf::Event& event)
{
    switch (event.Type)
    {
        case sf::Event::MouseMoved:
            for (std::map<std::string, Button>::iterator it = this->buttons.begin(); it != this->buttons.end(); ++it)
            {
                if (it->second.isClickedOn(sf::Vector2f(event.MouseMove.X, event.MouseMove.Y)))
                {
                    it->second.changeBorderColor(sf::Color::Red);
                }
                else
                {
                    it->second.changeBorderColor();
                }
            }
        case sf::Event::MouseButtonReleased:
            switch (event.MouseButton.Button)
            {
                case sf::Mouse::Left:
                    for (std::map<std::string, TextInput>::iterator it = this->textinputs.begin(); it != this->textinputs.end(); ++it)
                    {
                        if (it->second.isClickedOn(sf::Vector2f(event.MouseButton.X, event.MouseButton.Y)))
                        {
                            it->second.changeBorderColor(sf::Color::Red);
                        }
                        else
                        {
                            it->second.changeBorderColor();
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case sf::Event::TextEntered:
        {
            TextInput* tifocus = getFocusTextInput();
            if (tifocus != NULL)
            {
                tifocus->handleText(event.Text.Unicode);
            }
        }
            break;
        default:
            break;
    }
}

TextInput* Interface::getFocusTextInput()
{
    for (std::map<std::string, TextInput>::iterator it = this->textinputs.begin(); it != this->textinputs.end(); ++it)
    {
        if (it->second.getFocus())
        {
            return &it->second;
        }
    }
    return NULL;
}

TextInput* Interface::getTextInput(std::string name)
{
    return &this->textinputs[name];
}

void Interface::addAfter(std::string first, std::string next)
{
    TextInput* first_ti = &this->textinputs[first];
    TextInput* next_ti = &this->textinputs[next];
    next_ti->addAfter(first_ti);
}