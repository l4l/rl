#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Input.H"

#include "InitWindow.h"

InitWindow *InitWindow::_instance;

InitWindow::InitWindow() {
    _window = new Fl_Window(305, 305);
    _window->begin();

    _logBtn = new Fl_Button(75, 190, 165, 30, "&Login");
    _regBtn = new Fl_Button(75, 230, 165, 30, "&Register");

    _logIn = new Fl_Input(100, 60, 165, 20, "Nickname:");
    _regIn = new Fl_Input(100, 100, 165, 20, "Password:");

    _window->end();
}

InitWindow::~InitWindow() {
    _window->~Fl_Window();
}

int InitWindow::show() {
    _window->show();
    return Fl::run();
}

InitWindow InitWindow::getInstance() {
    if (!_instance) {
        _instance = new InitWindow;
    }
    return *_instance;
}
