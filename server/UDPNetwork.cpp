#include <iostream>
#include "UDPNetwork.h"

UDPNetwork::UDPNetwork() {
}

UDPNetwork::UDPNetwork(const UDPNetwork& orig) {
}

UDPNetwork::~UDPNetwork() 
{
    this->socket.Close();
}

void UDPNetwork::launch()
{
    libconfig::Config cfg;
    try
    {
        cfg.readFile("configuration.cfg");
    }
    catch (const libconfig::FileIOException &fioex)
    {
        std::cerr << "I/O error while reading file." << std::endl;
        exit(0);
    }
    catch (const libconfig::ParseException &pex)
    {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                << " - " << pex.getError() << std::endl;
        exit(0);
    }
    
    try
    {
        int port = cfg.lookup("server_configuration.connection.port");
        this->port = port;

        std::cout << "SERVER UDPNetwork::launch" << std::endl;
        if(this->socket.Bind(port))
            return;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cerr << "Setting not found" << std::endl;
        exit(0);
    }
}

void UDPNetwork::receiveData()
{
    std::cout << "SERVER UDPNetwork::receiveDATA" << std::endl;
    sf::IPAddress client_address;
    unsigned short client_port;
    char msg[128];
    std::size_t received;
    
    if(this->socket.Receive(msg, sizeof(msg), received, client_address, client_port) != sf::Socket::Done)
        return;
    
    this->addClient(client_address);
    
    std::cout << "Message received : " << msg << std::endl;
}

void UDPNetwork::addClient(sf::IPAddress ipaddress)
{
    bool can_add = true;
    for(std::vector<sf::IPAddress>::iterator it = this->clients_addresses.begin(); it != this->clients_addresses.end(); ++it)
    {
        if(*it == ipaddress)
        {
            can_add = false;
        }
        std::cout << *it << std::endl;
    }
    
    if(can_add == true)
    {
        this->clients_addresses.push_back(ipaddress);
    }
}