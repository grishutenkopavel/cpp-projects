#include "../include/window.hpp"
#include "../include/quad.hpp"

int main(int argc, char *argv[])
{
    Window *window = new Window(500, 500);

    Quad floor(1, 1, 2, 2);

    window->drawObject(floor);

    window->show();
    delete window;
    return 0;
}