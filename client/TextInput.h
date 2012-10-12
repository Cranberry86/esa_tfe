#ifndef TEXTINPUT_H
#define	TEXTINPUT_H

#include "Widget.h"
#include <SFML/Graphics.hpp>

class TextInput : public Widget {
public:
    TextInput();
    TextInput(sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color);
    TextInput(sf::Vector2f size, sf::Color color, int border_size);
    TextInput(const TextInput& orig);
    virtual ~TextInput();
    std::string getName();
protected:
    void Render(sf::RenderTarget& Target) const
    {
        Target.Draw(this->rect);
    }
};

#endif	/* TEXTINPUT_H */

