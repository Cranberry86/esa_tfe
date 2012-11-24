/* 
 * File:   RoundedBackground.cpp
 * Author: cranberry
 * 
 * Created on 24 novembre 2012, 10:28
 */

#include "RoundedBackground.h"
#include "RoundedRectShape.h"

RoundedBackground::RoundedBackground(){}

RoundedBackground::RoundedBackground(sf::Vector2f position, sf::Vector2f size, float radius, unsigned int points, sf::Color color, int border_size, sf::Color border_color)
{
    this->rect = RoundedRectShape(position.x, position.y, size.x, size.y, radius, points, color, border_size, border_color);
}

RoundedBackground::RoundedBackground(const RoundedBackground& orig)
{
}

RoundedBackground::~RoundedBackground()
{
}

