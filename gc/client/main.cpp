#include <iostream>

#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include <FL/Fl_Box.H>
#include "FL/Fl_Text_Display.H"

#include <net/NetInf.h>
#include "win/InitWindow.h"
#include "net/Loginer.h"


Fl_Text_Buffer *map = new Fl_Text_Buffer;
uint size = 0;

void gen(void*) {
    for (int i = 0; i < 80; i++)
        map->insert(size++, "a");
    map->insert(size++, "\n");
    Fl::add_timeout(1.5, gen);
}

int main() {
    InitWindow::setCallback([] (std::string name,
                                std::string pass,
                                bool isLogin) {
        transfer(HOST, LOG_PORT, name, pass, isLogin);
    });
    InitWindow::getInstance()->show();
    Fl_Window *window = new Fl_Window(860, 505);
    // 80x20
    Fl_Text_Display *o = new Fl_Text_Display(125, 75, 730, 425);
    Fl_Box *box = new Fl_Box(125, 75, 730, 425);
    o->scrollbar_width(0);
    o->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    o->position_style(4, 20, 3);
    o->labelfont(FL_SCREEN_BOLD);
    o->buffer(map);
    Fl::add_timeout(.5, gen);
    window->show();
    return Fl::run();
}