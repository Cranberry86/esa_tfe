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

Button::Button(sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color)
: Widget(size, color, border_size, border_color)
{
    
}

Button::Button(sf::Vector2f size, sf::Color color, int border_size)
: Widget(size, color, border_size)
{
    
}

Button::Button(const Button& orig)
{
}

Button::~Button()
{
}
