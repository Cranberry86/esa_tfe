/* 
 * File:   BakgroundImage.h
 * Author: cranberry
 *
 * Created on 7 octobre 2012, 17:10
 */

#ifndef BAKGROUNDIMAGE_H
#define	BAKGROUNDIMAGE_H

#include "ImageManager.h"
#include "Widget.h"
#include <SFML/Graphics.hpp>
#include <iostream>


class BackgroundImage : public sf::Sprite {
public:
    BackgroundImage();
    BackgroundImage(const std::string& filename);
    BackgroundImage(const BackgroundImage& orig);
    virtual ~BackgroundImage();
    void setSpriteFromImage();
private:
    ImageManager image_manager;
    sf::Image image;
};

#endif	/* BAKGROUNDIMAGE_H */

