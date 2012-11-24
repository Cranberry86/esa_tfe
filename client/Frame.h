/* 
 * File:   Frame.h
 * Author: cranberry
 *
 * Created on 24 novembre 2012, 16:22
 */

#ifndef FRAME_H
#define	FRAME_H

#include <SFML/Graphics.hpp>

class Frame {
public:
    Frame(const Frame& orig);
    virtual ~Frame();
    Frame(sf::Image* img, const sf::Rect<int>& rect, const sf::Color& alpha = sf::Color::White);
    Frame(sf::Image* img, const sf::Color& alpha = sf::Color::White);
    sf::Rect<int>& getRect();
    sf::Image* getImage();
private:
    sf::Image* img;
    sf::Rect<int> rect; 
    sf::Color alpha;
};

#endif	/* FRAME_H */

