#include <cstdlib>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

#include "UDPNetwork.h"
#include "SQLManager.h"
#include "ThreadManager.h"

#include <map>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    UDPNetwork network;
    network.launch();
    
    SQLManager sql_manager;
    sql_manager.launch();
//    std::map<std::string, std::string> datas = sql_manager.getData(2, "test");
//    
//    std::map<std::string, std::string>::iterator it;
//    for(it = datas.begin(); it != datas.end(); ++it)
//    {
//        std::cout << it->second << std::endl;
//    }
    
    sql_manager.saveData(91, "Plumes de paon", "test");
    
//    ThreadManager thread;
//    thread.Launch();
//    
//    for (int i = 0; i < 1000; ++i)
//        std::cout << "I'm the main thread" << std::endl;
    
//    std::vector< std::map< std::string, std::string> > datas = sql_manager.getAllData("test");
//    std::vector< std::map< std::string, std::string> >::iterator it;
//    for(it = datas.begin(); it != datas.end(); ++it)
//    {
//        std::map< std::string, std::string>::iterator in_it;
//        for(in_it = (*it).begin(); in_it != (*it).end(); ++in_it)
//        {
//            std::cout << in_it->second << std::endl;
//        }
//        
//    }
    
    sf::RenderWindow app(sf::VideoMode(300, 100, 32), "Server");
    
    while(app.IsOpened())
    {
        sf::Event event;
        while(app.GetEvent(event))
        {
            switch(event.Type)
            {
                case sf::Event::Closed:
                    app.Close();
                    break;
                default:
                    break;
            }
        }
        network.receiveData();
    }
    
    return 0;
}

