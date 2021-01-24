#include "../include/window.hpp"

int main(int argc, char *argv[])
{
    Window *window = new Window(800, 600);
    window->show();
    delete window;
    return 0;
}