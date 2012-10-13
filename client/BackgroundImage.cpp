/* 
 * File:   BakgroundImage.cpp
 * Author: cranberry
 * 
 * Created on 7 octobre 2012, 17:10
 */

#include "BackgroundImage.h"

BackgroundImage::BackgroundImage()
{
}

BackgroundImage::BackgroundImage(const BackgroundImage& orig):image(orig.image)
{
    this->SetImage(image);
}

BackgroundImage::~BackgroundImage()
{
}

BackgroundImage::BackgroundImage(const std::string& filename)
{
    if(!image.LoadFromFile(filename))
    {
        std::cout << "Erreur lors du chargement de l'image du Player." << std::endl;
    }
}

void BackgroundImage::setSpriteFromImage()
{
    this->SetImage(image);
}