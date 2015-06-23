#include "stdlib.h"
#include "boost/locale.hpp"
#include "Connection.h"

int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }

    std::string host = argv[1];
    unsigned short port = atoi(argv[2]);

    Connection handler(host, port);
    if (!handler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    char info[256];
    info[0] = 0;
    const char* user = "kitsu";
    const char* pass = "password";
    strcpy(info+1, user);
    strcpy(info+129, pass);

    //send the string to the server:
    if (!handler.send(info, 256)) {
        std::cout << "Disconnected. Exiting...\n" << std::endl;
        return 1;
    }


    //get the echo back from the server as simple bytes:
    char answer;
    if (!handler.recv(&answer, 1)) {
        std::cout << "Disconnected. Exiting...\n" << std::endl;
        return 1;
    }

    std::cout<< (answer == 0 ? "Ok.": "Wrong.");

    return 0;
}