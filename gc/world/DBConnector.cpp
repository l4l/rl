#include <iostream>
#include "DBConnector.h"

DBConnector::DBConnector() {
    mysql_init(&mysql);

    std::fstream data("data.inf", std::ios::in);
    std::string name, pass;

    char line[256];
    while (data.getline(line, 256)) {
        std::string t(line);
        if (t.substr(0, 4) == "user") {
            name = t.substr(5, t.length()-5);
        } else if (t.substr(0, 8) == "password") {
            pass = t.substr(9, t.length()-9);
        }
    }
    con = mysql_real_connect(&mysql, "localhost",
                             name.c_str(), pass.c_str(),
                             "users", 3306, 0, 0);

}
