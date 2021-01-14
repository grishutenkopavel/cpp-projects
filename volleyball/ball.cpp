#include <math.h>
#include <GL/gl.h>
#include <math.h>
#include "include/ball.hpp"

Ball::Ball(float x, float y, float dx, float dy, float r)
    :
    x(x),
    y(y),
    dx(dx),
    dy(dy),
    r(r) {}

void Ball::render(int cnt)
{
    float x, y;
    float da = M_PI * 2.0 / cnt;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0);
        for(int i = 0; i <= cnt; i++)
        {
            x = sin(da * i);
            y = cos(da * i);
            glVertex2f(x, y);
        }
    glEnd();
}