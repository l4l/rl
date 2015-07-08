#include "boost/locale.hpp"
#include "Connection.h"

#include "Loginer.h"

using namespace login;

void parseAnswer(char *answer, LoginAnswer &packet) {
    if (ANS_OK == (packet.answer = (answer[0] == ANS_OK) ?
                                   ANS_OK : ANS_BAD)) {
        strcpy(packet.token, answer+1);
    }
}

char* transfer(const std::string host, short port,
             const std::string user, const std::string pass, bool isLogin) {

    Connection handler(host, port);
    if (!handler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return nullptr;
    }

    LoginSend packetTo;
    packetTo.loginFlag = isLogin ? SEND_LOGIN : SEND_REG;
    strcpy(packetTo.user, user.c_str());
    strcpy(packetTo.pass, pass.c_str());

    //send the string to the server:
    if (!handler.send(reinterpret_cast<char*>(&packetTo), sizeof(packetTo))) {
        std::cerr << "Disconnected. Exiting...\n" << std::endl;
        return nullptr;
    }


    //get the echo back from the server as simple bytes:
    LoginAnswer packetFrom;
    char answer[2+TOKEN_SIZE];
    if (!handler.recv(answer, 2 + TOKEN_SIZE)) {
        std::cerr << "Disconnected. Exiting...\n" << std::endl;
        return nullptr;
    }

    parseAnswer(answer, packetFrom);
    std::clog<< (packetFrom.answer ? "Ok." : "Wrong.");

    return packetFrom.token;
}
