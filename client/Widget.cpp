#include <SFML/Graphics/RenderTarget.hpp>

#include "Widget.h"

Widget::Widget()
{
}

Widget::Widget(sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color)
{
    this->rect = sf::Shape::Rectangle(0, 0, size.x, size.y, color, border_size, border_color);
    this->border_color = border_color;
    this->color = color;
    this->size = size;
}

Widget::Widget(sf::Vector2f size, sf::Color color, int border_size)
{
    this->rect = sf::Shape::Rectangle(0, 0, size.x, size.y, color, border_size, sf::Color::Black);
    this->border_color = sf::Color::Black;
    this->color = color;
    this->size = size;
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
    if (point.x <= this->GetPosition().x)
        return false;
    else if (point.x >= this->GetPosition().x+this->size.x)
        return false;
    else if (point.y <= this->GetPosition().y)
        return false;
    else if (point.y >= this->GetPosition().y+this->size.y)
        return false;

    return true;
}

void Widget::changeBorderColor(sf::Color border_color)
{
        this->rect = sf::Shape::Rectangle(rect.GetPosition().x, rect.GetPosition().y, size.x, size.y, this->color, 1, border_color);
}

void Widget::changeBorderColor()
{
        this->rect = sf::Shape::Rectangle(rect.GetPosition().x, rect.GetPosition().y, size.x, size.y, this->color, 1, this->border_color);
}