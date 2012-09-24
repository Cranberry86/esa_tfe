#include "TextInput.h"

TextInput::TextInput()
{
    this->rect = sf::Shape::Rectangle(0,0,100,20,sf::Color::White,1,sf::Color::White);
}

TextInput::TextInput(const TextInput& orig)
{
}

TextInput::~TextInput()
{
}
