/* 
 * File:   Action.h
 * Author: cranberry
 *
 * Created on 25 novembre 2012, 12:12
 */

#ifndef ACTION_H
#define	ACTION_H

#include "UDPNetwork.h"
#include <iostream>


class Action {
public:
//    Action();
    static void login(UDPNetwork* network, std::string login, std::string pwd);
private:
    
};

#endif	/* ACTION_H */

