//#include <mysql++/connection.h>
//#include <mysql++/query.h>

#include <mysql/mysql.h>

#include "SQLManager.h"
#include "ObjetTest.h"

SQLManager::SQLManager()
{
}

bool SQLManager::launch()
{
    mysql_init(&this->mysql);
}

SQLManager::SQLManager(const SQLManager& orig)
{
}

SQLManager::~SQLManager()
{
    this->close();
}

void SQLManager::close()
{
    mysql_close(&this->mysql);
}

bool SQLManager::saveData(int format, std::string value, std::string table)
{
    if (mysql_real_connect(&this->mysql, "127.0.0.1", "root", "mysql", "esa_tfe", 0, NULL, 0))
    {
        std::ostringstream query;
        query << "INSERT INTO " << table << " (format, value) VALUES ( " << format << ",\"" << value << "\" ) ";
        std::cout << query.str() << std::endl;
        mysql_query(&this->mysql, query.str().c_str());
    }
    else
    {
        std::cout << "Une erreur s'est produite lors de la connexion à la BDD!";
    }
}

// TODO : sprintf

std::map<std::string, std::string> SQLManager::getData(int id, std::string table)
{
    std::map<std::string, std::string> results;
    // !! localhost doesn't work on linux, see fav
    if (mysql_real_connect(&this->mysql, "127.0.0.1", "root", "mysql", "esa_tfe", 0, NULL, 0))
    {
        std::ostringstream query;
        query << "SELECT * FROM " << table << " WHERE id = " << id;
        std::cout << query.str() << std::endl;
        mysql_query(&this->mysql, query.str().c_str());

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        MYSQL_FIELD *fields;
        unsigned int num_champs = 0;

        num_champs = mysql_field_count(&this->mysql);

        result = mysql_use_result(&this->mysql);

        fields = mysql_fetch_fields(result);

        while ((row = mysql_fetch_row(result)))
        {
            unsigned long *lengths;

            lengths = mysql_fetch_lengths(result);
            for (int i = 0; i < num_champs; i++)
            {
                results[fields[i].name] = row[i];
                //                std::cout << row[i] << std::endl;
            }

        }

        mysql_free_result(result);
    }
    else
    {
        std::cout << "Une erreur s'est produite lors de la connexion à la BDD!";
    }

    return results;
}

std::vector< std::map< std::string, std::string> > SQLManager::getAllData(std::string table)
{
    std::vector< std::map< std::string, std::string> > results;
    // !! localhost doesn't work on linux, see fav
    if (mysql_real_connect(&this->mysql, "127.0.0.1", "root", "mysql", "esa_tfe", 0, NULL, 0))
    {
        std::ostringstream query;
        query << "SELECT * FROM " << table;
        std::cout << query.str() << std::endl;
        mysql_query(&this->mysql, query.str().c_str());

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        MYSQL_FIELD *fields;
        unsigned int num_champs = 0;

        num_champs = mysql_field_count(&this->mysql);

        result = mysql_use_result(&this->mysql);

        fields = mysql_fetch_fields(result);

        while ((row = mysql_fetch_row(result)))
        {
            unsigned long *lengths;

            lengths = mysql_fetch_lengths(result);
            for (int i = 0; i < num_champs; i++)
            {
                std::map< std::string, std::string> result;
                result[fields[i].name] = row[i];
                results.push_back(result);
            }

        }

        mysql_free_result(result);
    }
    else
    {
        std::cout << "Une erreur s'est produite lors de la connexion à la BDD!";
    }

    return results;
}