/* 
 * File:   RoundedRectShape.h
 * Author: cranberry
 *
 * Created on 24 novembre 2012, 9:48
 * 
 * Taken from http://en.sfml-dev.org/forums/index.php?topic=973.0
 * and modified to fit my needs
 */

#ifndef ROUNDEDRECTSHAPE_H
#define	ROUNDEDRECTSHAPE_H

#include <SFML/Graphics/Shape.hpp>

class RoundedRectShape : public sf::Shape {
public:
    RoundedRectShape(float x, float y, float rectWidth, float rectHeight, float radius, unsigned int points, const sf::Color& Col, float Outline, const sf::Color& OutlineCol);
    RoundedRectShape(const RoundedRectShape& orig);
    virtual ~RoundedRectShape();
private:
};

#endif	/* ROUNDEDRECTSHAPE_H */

