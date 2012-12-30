/* 
 * File:   Button.h
 * Author: cranberry
 *
 * Created on 3 octobre 2012, 21:22
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "Widget.h"
#include "Observee.h"


class Button : public Widget, public Observee {
public:
    Button();
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color);
    Button(const Button& orig);
    virtual ~Button();
    
    void init();
private:
//    void Render(sf::RenderTarget& Target) const
//    {
//        Target.Draw(this->rect);
//    }
};

#endif	/* BUTTON_H */

