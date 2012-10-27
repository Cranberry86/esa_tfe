#ifndef WIDGET_H
#define	WIDGET_H

#include <SFML/Graphics.hpp>

#include <iostream>

class Widget : public sf::Drawable {
public:
    Widget();
    Widget(sf::Vector2f position, sf::Vector2f size, sf::Color bg_color, int border_size, sf::Color border_color);
    Widget(const Widget& orig);
    virtual ~Widget();
    virtual void setName(const std::string& name);
    virtual std::string getName();
    bool isClickedOn(sf::Vector2f point) const;
    void changeBorderColor(sf::Color border_color);
    void changeBorderColor();
    void setFocus(bool value);
    bool getFocus();
    void setTextSize(int size);
    void setTextColor(sf::Color color);
    void setFont();
    void setText(std::string text);
    
    void init();
protected:
    std::string name;
    sf::Shape rect;
    virtual void Render(sf::RenderTarget& Target) const
    {
        Target.Draw(this->rect);
        Target.Draw(draw_text);
    }
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color border_color;
    sf::Color bg_color;
    int border_size;
    bool focus;
    sf::Font font;
    sf::String draw_text;
    int text_size;
    sf::Color text_color;
    std::string input_text;
};

#endif	/* WIDGET_H */

