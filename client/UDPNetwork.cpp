#include <iostream>

#include "UDPNetwork.h"

UDPNetwork::UDPNetwork()
{
    this->awaiting_answer = false;
}

UDPNetwork::UDPNetwork(const UDPNetwork& orig)
{
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
        // voir doc de la library, pour le string, besoin de la conversion const char*
        std::string ip = cfg.lookup("client_configuration.connection.ip").c_str();
        int port = cfg.lookup("client_configuration.connection.port");

        this->client_port = port;
        this->server_address = ip;
        
        if(this->socket.Bind(this->client_port))
            return;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cerr << "Setting not found" << std::endl;
        exit(0);
    }
}

void UDPNetwork::sendData()
{
    sf::Packet packet;
    std::string login = "Cranberry";
    std::string pwd = "password";
    sf::Int8 packet_type = 1;
    
    packet << packet_type << login << pwd;
    
    if (this->socket.Send(packet, this->server_address, 4343) != sf::Socket::Done)
        return;
    
    this->awaiting_answer = true;
}

void UDPNetwork::receiveData()
{
    sf::IPAddress server_address;
    unsigned short server_port;
    
    sf::Packet packet;
    std::string msg;
//    std::string pwd;
//    sf::Int8 packet_type;
    
    if(this->socket.Receive(packet, server_address, server_port) != sf::Socket::Done)
        return;
    
    this->awaiting_answer = false;
    
    packet >> msg;
    
    std::cout << "CLIENT UDPNetwork::receiveDATA  :  " << msg << std::endl;
}

bool UDPNetwork::isAwaitingAnswer()
{
    return this->awaiting_answer;
}