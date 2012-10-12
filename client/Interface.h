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
#include <iostream>
#include <map>

class Interface {
public:
    Interface();
    Interface(const Interface& orig);
    virtual ~Interface();
    void init();
//    void addWidget(Widget* widget);
//    void displayWidgets(sf::RenderWindow* window);
    void addWidget(Widget& widget);
    void displayWidgets(sf::RenderWindow* window);
    void addBg(BackgroundImage bg);
    void displayBg(sf::RenderWindow* window);
    void addButton(Button& btn);
    void addTextInput(TextInput& ti);
    void addBackgrounds(BackgroundImage& bg);
private:    
    BackgroundImage bg;
//    std::map<std::string, Widget> widgets;
    std::map<std::string, TextInput> textinputs;
    std::map<std::string, Button> buttons;
    std::map<std::string, BackgroundImage> backgrounds;
    
    std::map<std::string, Widget*> widgets;
};

#endif	/* INTERFACE_H */

