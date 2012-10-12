#ifndef WIDGET_H
#define	WIDGET_H

#include <SFML/Graphics.hpp>

#include <iostream>

class Widget : public sf::Drawable {
public:
    Widget();
    Widget(sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color);
    Widget(sf::Vector2f size, sf::Color color, int border_size);
    Widget(const Widget& orig);
    virtual ~Widget();
    virtual void setName(const std::string& name);
    virtual std::string getName();
protected:
    std::string name;
    sf::Shape rect;
    virtual void Render(sf::RenderTarget& Target) const
    {
        Target.Draw(this->rect);
    }
};

#endif	/* WIDGET_H */

