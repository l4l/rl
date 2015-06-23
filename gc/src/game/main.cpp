#include "string"

#include "../win/InitWindow.h"
#include "../net/Loginer.h"

int main() {
    InitWindow::setCallback([] (std::string name,
                                std::string pass,
                                bool isLogin) {
        transfer(HOST, PORT, name, pass, isLogin);
    });
    InitWindow::getInstance()->show();
    return 0;
}