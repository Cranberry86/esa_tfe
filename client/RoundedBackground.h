/* 
 * File:   RoundedBackground.h
 * Author: cranberry
 *
 * Created on 24 novembre 2012, 10:28
 */

#ifndef ROUNDEDBACKGROUND_H
#define	ROUNDEDBACKGROUND_H

#include "Widget.h"


class RoundedBackground : public Widget {
public:
    RoundedBackground();
    RoundedBackground(sf::Vector2f position, sf::Vector2f size, float radius, unsigned int points, sf::Color color, int border_size, sf::Color border_color);
    RoundedBackground(const RoundedBackground& orig);
    virtual ~RoundedBackground();
private:

};

#endif	/* ROUNDEDBACKGROUND_H */

