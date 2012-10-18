#ifndef UDPNETWORK_H
#define	UDPNETWORK_H

#include <SFML/Network.hpp>
#include <libconfig.h++>
#include <vector>
#include <map>

class UDPNetwork {
public:
    UDPNetwork();
    UDPNetwork(const UDPNetwork& orig);
    virtual ~UDPNetwork();
    void sendData(sf::IPAddress address, sf::Packet packet);
    void receiveData();
    void launch();
    void addClient(sf::IPAddress, unsigned short);
    void managePackets();
private:
    sf::SocketUDP socket;
    unsigned int server_port;
    std::map<sf::IPAddress, unsigned short> clients;
    std::map<sf::IPAddress, sf::Packet> messages;
};

#endif	/* UDPNETWORK_H */

