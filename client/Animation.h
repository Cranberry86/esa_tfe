/* 
 * File:   Animation.h
 * Author: cranberry
 *
 * Created on 24 novembre 2012, 14:40
 */

#ifndef ANIMATION_H
#define	ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Frame.h"

class Animation {
public:
    Animation();
    Animation(const Animation& orig);
    virtual ~Animation();
    void pushFrame(sf::Image& img, sf::IntRect rect, sf::Color color = sf::Color::White);
    Frame& getFrame(int frame);
    int getFramesSize();
private:
    std::vector<Frame> frames;
};

#endif	/* ANIMATION_H */

