/* 
 * File:   ImageManager.h
 * Author: cranberry
 *
 * Created on 7 octobre 2012, 14:53
 */

#ifndef IMAGEMANAGER_H
#define	IMAGEMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class ImageManager {
public:
    ImageManager();
    ImageManager(const ImageManager& orig);
    virtual ~ImageManager();
    bool loadImage(const std::string& filename);
    sf::Image& getImage(const std::string& filename);
    bool deleteImage(const std::string& filename);
private:
    std::map<std::string, sf::Image> images;
    sf::Image img;
};

#endif	/* IMAGEMANAGER_H */

