#ifndef TEXTINPUT_H
#define	TEXTINPUT_H

#include "Widget.h"
#include <SFML/Graphics.hpp>

class TextInput : public Widget {
public:
    TextInput();
    TextInput(const TextInput& orig);
    virtual ~TextInput();
    virtual void Render(sf::RenderTarget& Target) const{};
private:

};

#endif	/* TEXTINPUT_H */

