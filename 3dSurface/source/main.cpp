#include "../include/window.hpp"
#include "../include/quad.hpp"
#include "../include/cube.hpp"

int main(int argc, char *argv[])
{
    Window *window = new Window(500, 500);

    Quad *floor[10][10];
    for(int i = 0; i < 10; i++)
        for(int j = 0;  j < 10; j++)
        {
            floor[i][j] = new Quad(i, j,-1,-1);
            if(i*j % 2 == 0)
                floor[i][j]->setColor(1,1,1);
            window->drawObject(*floor[i][j]);
        }

    Cube cube;
    window->drawObject(cube);
    window->show();
    delete window;
    return 0;
}