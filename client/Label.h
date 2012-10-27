/* 
 * File:   Label.h
 * Author: cranberry
 *
 * Created on 27 octobre 2012, 11:19
 */

#ifndef LABEL_H
#define	LABEL_H

#include "Widget.h"
#include <iostream>


class Label : public Widget{
public:
    Label();
    Label(const Label& orig);
    Label(std::string text, int text_size, sf::Color text_color, sf::Vector2f position);
    virtual ~Label();
    void init();
private:
    virtual void Render(sf::RenderTarget& Target) const
    {
        Target.Draw(draw_text);
    }
};

#endif	/* LABEL_H */

