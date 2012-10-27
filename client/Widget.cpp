#include <SFML/Graphics/RenderTarget.hpp>

#include "Widget.h"

Widget::Widget()
{
}

Widget::Widget(sf::Vector2f position, sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color)
{
    this->rect = sf::Shape::Rectangle(0, 0, size.x, size.y, color, border_size, border_color);
    this->size = size;
    this->border_color = border_color;
    this->bg_color = color;
    this->border_size = border_size;
    this->focus = false;
    this->position = position;
}

Widget::Widget(const Widget& orig)
{
}

Widget::~Widget()
{
}

void Widget::setName(const std::string& name)
{
    this->name = name;
}

std::string Widget::getName()
{
    return this->name;
}

bool Widget::isClickedOn(sf::Vector2f point) const
{
    if (point.x <= this->position.x)
        return false;
    else if (point.x >= this->position.x + this->size.x)
        return false;
    else if (point.y <= this->position.y)
        return false;
    else if (point.y >= this->position.y + this->size.y)
        return false;

    return true;
}

void Widget::changeBorderColor(sf::Color border_color)
{
    this->focus = true;

    this->rect.SetPointOutlineColor(0, border_color);
    this->rect.SetPointOutlineColor(1, border_color);
    this->rect.SetPointOutlineColor(2, border_color);
    this->rect.SetPointOutlineColor(3, border_color);
}

void Widget::changeBorderColor()
{
    this->focus = false;

    this->rect.SetPointOutlineColor(0, this->border_color);
    this->rect.SetPointOutlineColor(1, this->border_color);
    this->rect.SetPointOutlineColor(2, this->border_color);
    this->rect.SetPointOutlineColor(3, this->border_color);
}

void Widget::setFocus(bool value)
{
    focus = value;
}

bool Widget::getFocus()
{
    return focus;
}

void Widget::setTextSize(int size)
{
    this->draw_text.SetSize(size);
}

void Widget::setTextColor(sf::Color color)
{
    this->draw_text.SetColor(color);
}

void Widget::setFont()
{
    this->draw_text.SetFont(this->font);
}

void Widget::setText(std::string text)
{
    this->draw_text.SetText(text);
}


void Widget::init()
{
    if(!this->font.LoadFromFile("/home/cranberry/www/esa_tfe/client/fonts/monkey.ttf"))
        std::cout << "echec chargement font" << std::endl;
    
    this->draw_text.SetFont(this->font);
    this->draw_text.SetColor(this->text_color);
    this->rect.SetPosition(this->position);
}