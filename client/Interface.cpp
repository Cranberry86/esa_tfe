/* 
 * File:   Interface.cpp
 * Author: cranberry
 * 
 * Created on 6 octobre 2012, 21:27
 */

#include <vector>

#include "Interface.h"
#include "Action.h"

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
        if(it->second->getVisible())
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

void Interface::registerRoundedBackground(RoundedBackground& rb)
{
    this->rbs[rb.getName()] = rb;
    this->rbs[rb.getName()].init();
    this->widgets[rb.getName()] = &this->rbs[rb.getName()];
}

void Interface::addBackground(std::string filename)
{
    BackgroundImage bg(imanager, filename);
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

void Interface::addRoundedBackground(std::string name, sf::Vector2f position, sf::Vector2f size, float radius, unsigned int points, sf::Color color, int border_size, sf::Color border_color)
{
    RoundedBackground rb(position, size, radius, points, color, border_size, border_color);
    rb.setName(name);
    registerRoundedBackground(rb);
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
                    break;
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
                            break;
                        }
                        else
                        {
                            it->second.changeBorderColor();
                        }
                    }
                    for (std::map<std::string, Button>::iterator it = this->buttons.begin(); it != this->buttons.end(); ++it)
                    {
                        if (it->second.isClickedOn(sf::Vector2f(event.MouseButton.X, event.MouseButton.Y)))
                        {
                            if(this->getTextInput("login_input")->getText() != "" && this->getTextInput("pwd_input")->getText() != "")
                            {
                                this->getWidget("label_error")->setVisible(false);
                                //Action::login(this->network, this->getTextInput("login_input")->getText(), this->getTextInput("pwd_input")->getText());
                                it->second.NotifyObservers();
                            }
                            else
                            {
                                this->getWidget("label_error")->setVisible(true);
                            }
                            break;
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

Button* Interface::getButton(std::string name)
{
    return &this->buttons[name];
}

void Interface::addAfter(std::string first, std::string next)
{
    TextInput* first_ti = &this->textinputs[first];
    TextInput* next_ti = &this->textinputs[next];
    next_ti->addAfter(first_ti);
}

void Interface::setImageManager(ImageManager* imanager)
{
    this->imanager = imanager;
}

void Interface::setNetwork(UDPNetwork* network)
{
    this->network = network;
}