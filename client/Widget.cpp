#include <SFML/Graphics/RenderTarget.hpp>

#include "Widget.h"

Widget::Widget()
{
}

Widget::Widget(sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color)
{
    this->rect = sf::Shape::Rectangle(0, 0, size.x, size.y, color, border_size, border_color);
}

Widget::Widget(sf::Vector2f size, sf::Color color, int border_size)
{
    this->rect = sf::Shape::Rectangle(0, 0, size.x, size.y, color, border_size);
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