/* 
 * File:   AnimatedSprite.cpp
 * Author: cranberry
 * 
 * Created on 24 novembre 2012, 15:03
 */

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
    this->time = 0.1f;
    this->elapsed_time = this->time;
    this->current_frame = 0;
}

AnimatedSprite::AnimatedSprite(const AnimatedSprite& orig)
{
}

AnimatedSprite::~AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(float time)
{
    this->time = time;
    this->elapsed_time = time;
    this->current_frame = 0;
}

void AnimatedSprite::setAnimation(Animation* anim)
{
    this->animation = anim;
}

void AnimatedSprite::setFrameTime(float time)
{
    this->time = time;
}

void AnimatedSprite::play(float elapsed_time)
{
    if(this->animation != NULL)
    {
        this->elapsed_time -= elapsed_time;
        if(this->elapsed_time <= 0.f)
        {
            this->elapsed_time = this->time;
            if(current_frame + 1 < this->animation->getFramesSize())
            {
                current_frame++;
            }
            else
            {
                current_frame = 0;
            }
            this->setFrame(current_frame);
        }
    }
}

void AnimatedSprite::stop()
{
    
}

void AnimatedSprite::setFrame(int frame)
{
    if(this->animation != NULL)
    {
        if(frame < this->animation->getFramesSize())
        {
            this->SetSubRect(this->animation->getFrame(frame));
        }
    }
}