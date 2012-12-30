/* 
 * File:   Interface.h
 * Author: cranberry
 *
 * Created on 6 octobre 2012, 21:27
 */

#ifndef INTERFACE_H
#define	INTERFACE_H

#include "Widget.h"
#include "BackgroundImage.h"
#include "Button.h"
#include "TextInput.h"
#include "Label.h"
#include "RoundedBackground.h"
#include "UDPNetwork.h"
#include <iostream>
#include <map>

class Interface {
public:
    Interface();
    Interface(const Interface& orig);
    virtual ~Interface();
    void init();
    void addWidget(Widget& widget);
    void displayWidgets(sf::RenderWindow* window);
    void addBg(BackgroundImage bg);
    void displayBg(sf::RenderWindow* window);
    void addBackground(std::string filename);
    void addButton(std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color bg_color, int border_size, sf::Color border);
    void addTextInput(std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color bg_color, int border_size, sf::Color border);
    Widget* getWidget(std::string name);
    TextInput* getTextInput(std::string name);
    Button* getButton(std::string name);
    void handleEvents(sf::Event& event);
    void addLabel(std::string name, std::string text, int text_size, sf::Color text_color, sf::Vector2f position);
    void addAfter(std::string first, std::string next);
    void addRoundedBackground(std::string name, sf::Vector2f position, sf::Vector2f size, float radius, unsigned int points, sf::Color color, int border_size, sf::Color border_color);
    
    void setImageManager(ImageManager* imanager);
    void setNetwork(UDPNetwork* network);
private:
    void registerButton(Button& btn);
    void registerTextInput(TextInput& ti);
    void registerLabel(Label& label);
    void registerRoundedBackground(RoundedBackground& rb);
    
    BackgroundImage bg;
    std::map<std::string, TextInput> textinputs;
    std::map<std::string, Button> buttons;
    std::map<std::string, BackgroundImage> backgrounds;
    std::map<std::string, Label> labels;
    std::map<std::string, RoundedBackground> rbs;
    
    std::map<std::string, Widget*> widgets;
    TextInput* getFocusTextInput();
    
    ImageManager* imanager;
    UDPNetwork* network;
};

#endif	/* INTERFACE_H */

