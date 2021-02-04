#include "../include/cube.hpp"


float cubeVertex[] = {
    4.5, 5.5, 1, //0
    4.5, 4.5, 1, //1
    5.5, 4.5, 1, //2
    5.5, 5.5, 1, //3
    4.5, 5.5, 0, //4
    4.5, 4.5, 0, //5
    5.5, 4.5, 0,//6
    5.5, 5.5, 0//7

};

float cubeColor[] = {
    1,0,0,
    0,1,0,
    0,0,1,
    1,1,0,
    1,0,0,
    0,1,0,
    0,0,1,
    1,1,0
};

GLuint cube[] = {
    0,1,2,3,
    1,5,6,2,
    0,1,5,4,
    2,3,7,6,
    0,3,7,4,
    4,5,6,7
};

void Cube::draw()
{
    glVertexPointer(3, GL_FLOAT, 0, &cubeVertex);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, &cubeColor);
    glEnableClientState(GL_COLOR_ARRAY);
        glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, &cube);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}