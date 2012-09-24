#include <mysql++/connection.h>
#include <mysql++/query.h>

#include "SQLManager.h"
#include "ObjetTest.h"

SQLManager::SQLManager()
{
}

bool SQLManager::launch()
{
    mysqlpp::Connection conn(false);
    if (conn.connect("esa_tfe", "localhost", "root", "mysql"))
    {
        std::cout << "CONNEXION OK" << std::endl;
    }
    else
    {
        std::cout << "ERROR DO CONNEXION" << std::endl;
    }
    this->conn = conn;
}

SQLManager::SQLManager(const SQLManager& orig)
{
}

SQLManager::~SQLManager()
{
    this->conn.disconnect();
}

bool SQLManager::saveData(int format, std::string value, std::string table)
{
//    sql_create_2(test, 2, 2, mysqlpp::sql_bigint, format, mysqlpp::sql_mediumtext_null, value);
            
    std::cout << "SAVE DATA" << std::endl;
    
    test row(mysqlpp::sql_bigint(format), mysqlpp::sql_varchar_null(value));
    
    mysqlpp::Query query = this->conn.query();
    query << "INSERT INTO " << table << " (format, value) VALUES (" << format << ", " << mysqlpp::quote << value << ")";
//    query.insert(row);
    query.execute();
}

std::map<std::string, std::string> SQLManager::getData(int id, std::string table)
{
    std::map<std::string, std::string> result;
    
    mysqlpp::Query query = this->conn.query();
    
    query << "SELECT * FROM " << table << " where id = " << id;
    
    mysqlpp::UseQueryResult res = query.use();
    
    if (res)
    {
        mysqlpp::Row row = res.fetch_row();
        result["id"] = row["id"].c_str();
        result["value"] = row["value"].c_str();
        result["format"] = row["format"].c_str();
    }
    else
    {
        std::cerr << "Failed to get stock table: " << query.error() << std::endl;
    }
    
    return result;
}

std::vector< std::map< std::string, std::string> > SQLManager::getAllData(std::string table)
{
    std::vector< std::map< std::string, std::string> > results;
    mysqlpp::Query query = this->conn.query();
    query << "SELECT * FROM " << table;
    
    mysqlpp::StoreQueryResult res = query.store();
    
    if (res)
    {
        for (size_t i = 0; i < res.num_rows(); ++i)
        {
            std::map< std::string, std::string> result;
            result["id"] = res[i][0].c_str();
            result["value"] = res[i][1].c_str();
            result["format"] = res[i][2].c_str();
            results.push_back(result);
        }
    }
    else
    {
        std::cerr << "Failed to get stock table: " << query.error() << std::endl;
    }
    
    return results;
}