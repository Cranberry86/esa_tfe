/* 
 * File:   AnimatedSprite.h
 * Author: cranberry
 *
 * Created on 24 novembre 2012, 15:03
 */

#ifndef ANIMATEDSPRITE_H
#define	ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(float time = 0.f);
    AnimatedSprite(const AnimatedSprite& orig);
    virtual ~AnimatedSprite();
    void setAnimation(Animation* anim);
    void setFrameTime(float time);
    void setFrame(int frame);
    void play(float elapsed_time);
    void stop();
private:
    Animation* animation;
    float time;
    float elapsed_time;
    int current_frame;
};

#endif	/* ANIMATEDSPRITE_H */

