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

class Animation {
public:
    Animation();
    Animation(const Animation& orig);
    virtual ~Animation();
    void pushFrame(sf::Image& img, sf::IntRect rect);
    sf::IntRect& getFrame(int frame);
    int getFramesSize();
private:
    std::vector<sf::IntRect> frames;
};

#endif	/* ANIMATION_H */

