#ifndef SQLMANAGER_H
#define	SQLMANAGER_H

#include <iostream>
#include "mysql.h"
#include <mysql++.h>
#include <map>
#include <vector>
#include <ssqls.h>

class SQLManager {
public:
    SQLManager();
    SQLManager(const SQLManager& orig);
    virtual ~SQLManager();
    bool launch();
    bool saveData(int format, std::string value, std::string table);
    std::map<std::string, std::string> getData(int id, std::string table);
    std::vector< std::map< std::string, std::string> > getAllData(std::string table);
private:
    mysqlpp::Connection conn;
};

#endif	/* SQLMANAGER_H */

