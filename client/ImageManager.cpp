/* 
 * File:   ImageManager.cpp
 * Author: cranberry
 * 
 * Created on 7 octobre 2012, 14:53
 */

#include <SFML/Network/IPAddress.hpp>

#include "ImageManager.h"

ImageManager::ImageManager()
{
}

ImageManager::ImageManager(const ImageManager& orig)
{
}

ImageManager::~ImageManager()
{
}

bool ImageManager::loadImage(const std::string& filename)
{
    sf::Image image;
    if(!image.LoadFromFile(filename))
    {
        std::cout << "im::getimage ERROR" << std::endl;
        return false;
    }
    this->images[filename] = image;
}

sf::Image& ImageManager::getImage(const std::string& filename)
{
    for(std::map<std::string, sf::Image>::iterator it = this->images.begin(); it != this->images.end(); ++it)
    {
        if(filename == it->first)
        {
            return it->second;
        }
        std::cout << "im::getimage" << filename << std::endl;
    }
    
    this->loadImage(filename);
    return this->images[filename];
}

bool ImageManager::deleteImage(const std::string& filename)
{
    for(std::map<std::string, sf::Image>::iterator it; it != this->images.end(); ++it)
    {
        if(filename == it->first)
        {
            this->images.erase(it);
        }
    }
}