/* 
 * File:   Label.cpp
 * Author: cranberry
 * 
 * Created on 27 octobre 2012, 11:19
 */

#include "Label.h"

Label::Label()
{
}

Label::Label(const Label& orig)
{
}

Label::~Label()
{
}

Label::Label(std::string text, int text_size, sf::Color text_color, sf::Vector2f position)
{
    this->input_text = text;
    this->text_color = text_color;
    this->text_size = text_size;
    this->focus = false;
    this->position = position;
}

void Label::init()
{
    Widget::init();
    this->draw_text.SetText(this->input_text);
    this->draw_text.SetPosition(this->position);
}