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
        this->server_port = port;

        if(this->socket.Bind(this->server_port))
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
    
    sf::Packet packet;
//    std::string login;
//    std::string pwd;
//    sf::Int8 packet_type;
    
    if(this->socket.Receive(packet, client_address, client_port) != sf::Socket::Done)
    {
        std::cout << "SERVER UDPNetwork::receiveDATA ERROR" << std::endl;
        return;
    }
    
//    packet >> packet_type >> login >> pwd;
//    packet >> packet_type;
    
    this->addClient(client_address, client_port);
    this->messages[client_address] = packet;
}

void UDPNetwork::addClient(sf::IPAddress ipaddress, unsigned short port)
{
    this->clients[ipaddress] = port;
}

void UDPNetwork::managePackets()
{
    std::cout << "SERVER UDPNetwork::MANAGE PACKET" << std::endl;
    for(std::map<sf::IPAddress, sf::Packet>::iterator it = this->messages.begin(); it != this->messages.end(); ++it)
    {
        sf::Packet packet;
        std::string msg = "OKAY";
        packet << msg;
        sendData(it->first, packet);
        this->messages.erase(it);
    }
}

void UDPNetwork::sendData(sf::IPAddress address, sf::Packet packet)
{
    if (this->socket.Send(packet, address, this->clients[address]) != sf::Socket::Done)
    {
        return;
    }
}