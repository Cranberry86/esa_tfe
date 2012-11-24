/* 
 * File:   Animation.cpp
 * Author: cranberry
 * 
 * Created on 24 novembre 2012, 14:40
 */

#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(const Animation& orig)
{
}

Animation::~Animation()
{
}

void Animation::pushFrame(sf::Image& img, sf::IntRect rect)
{
    this->frames.push_back(rect);
}

sf::IntRect& Animation::getFrame(int frame)
{
    return this->frames[frame];
}

int Animation::getFramesSize()
{
    return this->frames.size();
}