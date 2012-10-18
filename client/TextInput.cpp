#include "TextInput.h"

TextInput::TextInput()
{
}

TextInput::TextInput(const TextInput& orig)
{
}

TextInput::TextInput(sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color)
: Widget(size, color, border_size, border_color)
{
    
}

TextInput::TextInput(sf::Vector2f size, sf::Color color, int border_size)
: Widget(size, color, border_size)
{
    
}

TextInput::~TextInput()
{
}
