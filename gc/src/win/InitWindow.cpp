#include <functional>
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Input.H"

#include "InitWindow.h"

InitWindow::~InitWindow() {
    _window->~Fl_Window();
}

int InitWindow::show() {
    _window->show();
    return Fl::run();
}

InitWindow* InitWindow::getInstance() {
    if (!instance)
        instance = new InitWindow;
    return instance;
}

void InitWindow::setCallback(void (*f)(std::string, std::string, bool)) {
    callback = f;
}

std::string InitWindow::getName() {
    return instance->_logIn->value();
}

std::string InitWindow::getPass() {
    return instance->_regIn->value();
}

void(*InitWindow::callback)(std::string, std::string, bool);
InitWindow *InitWindow::instance;

InitWindow::InitWindow() {

    _window = new Fl_Window(305, 305);
    _window->begin();

    _logBtn = new Fl_Button(75, 190, 165, 30, "&Login");
    _logBtn->callback(logCb);
    _regBtn = new Fl_Button(75, 230, 165, 30, "&Register");
    _regBtn->callback(regCb);

    _logIn = new Fl_Input(100, 60, 165, 20, "Nickname:");
    _regIn = new Fl_Input(100, 100, 165, 20, "Password:");

    _window->end();
}

void InitWindow::logCb(Fl_Widget *widget, void *p) {
    InitWindow *w = (InitWindow *)p;
    callback(w->getName(), w->getPass(), true);
}

void InitWindow::regCb(Fl_Widget *widget, void *p) {
    InitWindow *w = (InitWindow *)p;
    callback(w->getName(), w->getPass(), false);
}
