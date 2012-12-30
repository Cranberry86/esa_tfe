/* 
 * File:   StateObserver.cpp
 * Author: cranberry
 * 
 * Created on 30 décembre 2012, 14:07
 */

#include "ButtonObserver.h"
#include "Button.h"

ButtonObserver::ButtonObserver()
{
    this->btn = NULL;
}

ButtonObserver::ButtonObserver(const ButtonObserver& orig)
{
}

ButtonObserver::~ButtonObserver()
{
}

void ButtonObserver::Notify(Observee* observee)
{
    this->btn = (Button*) observee;
}

std::string ButtonObserver::getButtonName()
{
    return (this->btn == NULL) ? "" : this->btn->getName();
}