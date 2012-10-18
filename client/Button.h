/* 
 * File:   Button.h
 * Author: cranberry
 *
 * Created on 3 octobre 2012, 21:22
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "Widget.h"


class Button : public Widget {
public:
    Button();
    Button(sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color);
    Button(sf::Vector2f size, sf::Color color, int border_size);
    Button(const Button& orig);
    virtual ~Button();
private:
    void Render(sf::RenderTarget& Target) const
    {
        Target.Draw(this->rect);
    }
};

#endif	/* BUTTON_H */

