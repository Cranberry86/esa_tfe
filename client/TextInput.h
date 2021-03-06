#ifndef TEXTINPUT_H
#define	TEXTINPUT_H

#include "Widget.h"
#include <SFML/Graphics.hpp>

class TextInput : public Widget {
public:
    TextInput();
    TextInput(sf::Vector2f position, sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color);
    TextInput(const TextInput& orig);
    virtual ~TextInput();
    void handleText(const sf::Uint32& chara);
    void setMaxLength(int max);
    void init();
    void addAfter(TextInput* first);
    TextInput* getNext();
    TextInput* getFirst();
    void setFirst(TextInput* first);
    void setNext(TextInput* next);
protected:
    void handleDrawText();
    int max_length;
    int current_length;
    TextInput* next;
    TextInput* first;
};

#endif	/* TEXTINPUT_H */

