#ifndef CLIENT_DBCONNECTOR_H
#define CLIENT_DBCONNECTOR_H

#include "mysql/mysql.h"
#include "fstream"

class DBConnector {
public:
    DBConnector();
private:
    MYSQL mysql, *con;
};

#endif //CLIENT_DBCONNECTOR_H
