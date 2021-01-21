#include <gl/gl.h>

POINTFLOAT vertex[] = {
    {1, 0.3},
    {0.3, 0.7},
    {0.7, 1}
};
POINTFLOAT Z[] = {
    {-0.5, 0.5},
    {0.5, 0.5},
    {-0.5, -0.5},
    {0.5, -0.5}
};

float colors[] = {1,0,0, 0,1,0, 0,0,1, 1,1,0};

GLuint index[] = { 1,2,3,4};