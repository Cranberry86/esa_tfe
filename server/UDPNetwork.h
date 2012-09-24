#ifndef UDPNETWORK_H
#define	UDPNETWORK_H

#include <SFML/Network.hpp>
#include <libconfig.h++>

class UDPNetwork {
public:
    UDPNetwork();
    UDPNetwork(const UDPNetwork& orig);
    virtual ~UDPNetwork();
    void sendData();
    void receiveData();
    void launch();
private:
    sf::SocketUDP socket;
    unsigned int port;
};

#endif	/* UDPNETWORK_H */

