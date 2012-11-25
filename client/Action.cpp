/* 
 * File:   Action.cpp
 * Author: cranberry
 * 
 * Created on 25 novembre 2012, 12:12
 */

#include "Action.h"

void Action::login(UDPNetwork* network, std::string login, std::string pwd)
{
    sf::Packet packet;
    sf::Int8 packet_type = 1;
    packet << packet_type << login << pwd;
    
//    network->sendData(packet);
    
    std::cout << "coucou : " << login << " " << pwd << std::endl;
}