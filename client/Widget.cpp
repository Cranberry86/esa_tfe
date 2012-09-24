#include <SFML/Graphics/RenderTarget.hpp>

#include "Widget.h"

Widget::Widget()
{
}

Widget::Widget(const Widget& orig)
{
}

Widget::~Widget()
{
}

void Widget::setPosition(sf::Vector2f position)
{
    this->rect.SetPosition(position);
}

void Widget::display(sf::RenderWindow& window)
{
    window.Draw(this->rect);
}