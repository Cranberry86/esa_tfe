#ifndef WIDGET_H
#define	WIDGET_H

#include <SFML/Graphics.hpp>

class Widget : public sf::Drawable {
public:
    Widget();
    Widget(const Widget& orig);
    virtual ~Widget();
    void display(sf::RenderWindow &window);
    void setPosition(sf::Vector2f position);
    void setSize();
    virtual void Render(sf::RenderTarget& Target) const{};
protected:
    sf::Shape rect;
    sf::Vector2f position;
    sf::Vector2f size;
};

#endif	/* WIDGET_H */

