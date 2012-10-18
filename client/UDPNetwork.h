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
    bool isAwaitingAnswer();
private:
    sf::SocketUDP socket;
    unsigned int client_port;
    sf::IPAddress server_address;
    bool awaiting_answer;
};

#endif	/* UDPNETWORK_H */

