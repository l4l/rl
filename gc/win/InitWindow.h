#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Input.H"

#ifndef CLIENT_INITWINDOW_H
#define CLIENT_INITWINDOW_H

#include "string"

class InitWindow {
public:
    ~InitWindow();

    int show();

    static InitWindow* getInstance();

    static void setCallback(void(*f)(std::string name, std::string pas, bool isLogin));

    static std::string getName();
    static std::string getPass();
private:

    InitWindow();

    Fl_Window *_window;
    Fl_Button *_logBtn;

    Fl_Button *_regBtn;
    Fl_Input *_logIn;

    Fl_Input *_regIn;

    static void(*callback)(std::string, std::string, bool);

    static void logCb(Fl_Widget*, void*);
    static void regCb(Fl_Widget*, void*);

    static InitWindow *instance;
};

#endif //CLIENT_INITWINDOW_H
