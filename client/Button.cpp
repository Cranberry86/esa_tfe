/* 
 * File:   Button.cpp
 * Author: cranberry
 * 
 * Created on 3 octobre 2012, 21:22
 */

#include "Button.h"

Button::Button()
{
}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color)
: Widget(position, size, color, border_size, border_color)
{
    
}

Button::Button(const Button& orig)
{
}

Button::~Button()
{
}

void Button::init()
{
    Widget::init();
    
    this->draw_text.SetText(this->input_text);
    this->draw_text.SetPosition((this->position.x+this->size.x/2)-this->draw_text.GetSize()/2, this->position.y-5);
}
