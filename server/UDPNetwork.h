#ifndef UDPNETWORK_H
#define	UDPNETWORK_H

#include <SFML/Network.hpp>
#include <libconfig.h++>
#include <vector>

class UDPNetwork {
public:
    UDPNetwork();
    UDPNetwork(const UDPNetwork& orig);
    virtual ~UDPNetwork();
    void sendData();
    void receiveData();
    void launch();
    void addClient(sf::IPAddress);
private:
    sf::SocketUDP socket;
    unsigned int port;
    std::vector<sf::IPAddress> clients_addresses;
};

#endif	/* UDPNETWORK_H */

