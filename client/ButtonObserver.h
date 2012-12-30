/* 
 * File:   StateObserver.h
 * Author: cranberry
 *
 * Created on 30 décembre 2012, 14:07
 */

#ifndef BUTTONOBSERVER_H
#define	BUTTONOBSERVER_H

#include "Observer.h"
#include "Button.h"

#include <iostream>

class ButtonObserver : public Observer {
public:
    ButtonObserver();
    ButtonObserver(const ButtonObserver& orig);
    virtual ~ButtonObserver();
    void Notify(Observee* observee);
    std::string getButtonName();
private:
    Button* btn;
};

#endif	/* BUTTONOBSERVER_H */

