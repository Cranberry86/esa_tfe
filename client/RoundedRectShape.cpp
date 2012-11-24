/* 
 * File:   RoundedRectShape.cpp
 * Author: cranberry
 * 
 * Created on 24 novembre 2012, 9:48
 */

#include "RoundedRectShape.h"
#include <cmath>

RoundedRectShape::RoundedRectShape(float x, float y, float rectWidth, float rectHeight, float radius, unsigned int points, const sf::Color& Col, float Outline, const sf::Color& OutlineCol)
{
    this->SetOutlineWidth(Outline);
    float X = 0, Y = 0;
    for (int i = 0; i < points; i++)
    {
        X += radius / points;
        Y = sqrt(radius * radius - X * X);
        this->AddPoint(X + x + rectWidth - radius, y - Y + radius, Col, OutlineCol);
    }
    Y = 0;
    for (int i = 0; i < points; i++)
    {
        Y += radius / points;
        X = sqrt(radius * radius - Y * Y);
        this->AddPoint(x + rectWidth + X - radius, y + rectHeight - radius + Y, Col, OutlineCol);
    }
    X = 0;
    for (int i = 0; i < points; i++)
    {
        X += radius / points;
        Y = sqrt(radius * radius - X * X);
        this->AddPoint(x + radius - X, y + rectHeight - radius + Y, Col, OutlineCol);
    }
    Y = 0;
    for (int i = 0; i < points; i++)
    {
        Y += radius / points;
        X = sqrt(radius * radius - Y * Y);
        this->AddPoint(x - X + radius, y + radius - Y, Col, OutlineCol);
    }
}

RoundedRectShape::RoundedRectShape(const RoundedRectShape& orig)
{
}

RoundedRectShape::~RoundedRectShape()
{
}