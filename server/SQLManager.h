#ifndef SQLMANAGER_H
#define	SQLMANAGER_H

#include <iostream>
#include "mysql.h"
#include <mysql++.h>
#include <map>
#include <vector>
#include <ssqls.h>
#include <string>
#include <sstream>

class SQLManager {
public:
    SQLManager();
    SQLManager(const SQLManager& orig);
    virtual ~SQLManager();
    bool launch();
    bool saveData(int format, std::string value, std::string table);
    std::map<std::string, std::string> getData(int id, std::string table);
    std::vector< std::map< std::string, std::string> > getAllData(std::string table);
    void close();
private:
    mysqlpp::Connection conn;
    MYSQL mysql;
};

#endif	/* SQLMANAGER_H */

