#include "../include/window.hpp"
#include "../include/quad.hpp"

int main(int argc, char *argv[])
{
    Window *window = new Window(800, 600);

    Quad q1(0.5, 0.5, 1, 1);
    Quad q2(1, 1, 0.5, 0.5);

    window->drawObject(q1);
    window->drawObject(q2);

    window->show();
    delete window;
    return 0;
}