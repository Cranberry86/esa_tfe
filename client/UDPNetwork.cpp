#include <iostream>

#include "UDPNetwork.h"

UDPNetwork::UDPNetwork()
{
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

        this->port = port;
        this->server_address = ip;
        std::cout << "CLIENT UDPNetwork::launch" << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cerr << "Setting not found" << std::endl;
        exit(0);
    }
}

void UDPNetwork::sendData()
{
    std::cout << "CLIENT UDPNetwork::sendData" << std::endl;
    char msg[] = "Je suis un client !";

    if (this->socket.Send(msg, sizeof (msg), this->server_address, this->port) != sf::Socket::Done)
        return;

    std::cout << "Message sent !" << std::endl;
}