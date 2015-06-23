#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Input.H"

#ifndef CLIENT_INITWINDOW_H
#define CLIENT_INITWINDOW_H

class InitWindow {
private:
    InitWindow();
    Fl_Window *_window;

    Fl_Button *_logBtn;

    Fl_Button *_regBtn;
    Fl_Input *_logIn;

    Fl_Input *_regIn;
    static InitWindow *_instance;

public:
    ~InitWindow();

    int show();
    static InitWindow getInstance();
};


#endif //CLIENT_INITWINDOW_H
