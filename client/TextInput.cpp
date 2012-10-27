#include "TextInput.h"

TextInput::TextInput(){}

TextInput::TextInput(const TextInput& orig){}

TextInput::TextInput(sf::Vector2f position, sf::Vector2f size, sf::Color color, int border_size, sf::Color border_color)
: Widget(position, size, color, border_size, border_color)
{
    this->current_length = 0;
    this->max_length = 5;
}

TextInput::~TextInput(){}

void TextInput::handleText(const sf::Uint32& character)
{
    switch(character)
    {
        // Touche "Supprimer"
        case '\b':
            if(!this->input_text.empty())
            {
                this->input_text.erase(this->input_text.end()-1);
                this->current_length--;
            }
            break;
        default:
            if(this->current_length < this->max_length)
            {
                this->input_text += static_cast<wchar_t>(character);
                this->current_length++;
            }
            break;
    }
    handleDrawText();
}

void TextInput::handleDrawText()
{
    this->draw_text.SetText(this->input_text);
}

void TextInput::setMaxLength(int max)
{
    this->max_length = max;
}

void TextInput::init()
{
    Widget::init();
    
    this->draw_text.SetPosition(this->position.x+2, this->position.y-5);
}