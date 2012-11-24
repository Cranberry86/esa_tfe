/* 
 * File:   Frame.cpp
 * Author: cranberry
 * 
 * Created on 24 novembre 2012, 16:22
 */

#include <SFML/Graphics/Color.hpp>

#include "Frame.h"

Frame::Frame(const Frame& orig)
{
    this->img = orig.img;
    this->rect = orig.rect;
}

Frame::~Frame()
{
}

Frame::Frame(sf::Image* img, const sf::Color& alpha)
{
    this->img = img;
    if (this->img != NULL)
        this->rect = sf::Rect<int>(0, 0, this->img->GetWidth(), this->img->GetHeight());
 
    this->alpha = alpha;
}

Frame::Frame(sf::Image* img, const sf::Rect<int>& rect, const sf::Color& alpha)
{
    this->img = img;
    this->img->SetSmooth(false);
    this->img->CreateMaskFromColor(alpha);
    this->alpha = alpha;
    this->rect = rect;
}

sf::Rect<int>& Frame::getRect()
{
    return this->rect;
}

sf::Image* Frame::getImage()
{
    return this->img;
}