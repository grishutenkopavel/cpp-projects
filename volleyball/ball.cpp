#include <math.h>
#include <GL/gl.h>
#include <math.h>
#include "include/constants.hpp"
#include "include/ball.hpp"

Ball::Ball(float x, float y, float dx, float dy, float r)
    :
    gravity(0.02),
    x(x),
    y(y),
    dx(dx),
    dy(dy),
    r(r) {}

void Ball::drawBall(int cnt)
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
void  Ball::reflect(float *da, float *a, bool cond, float wall)
{
    if (!cond) return;
    *da *= -0.85;
    *a = wall;
}
void Ball::render()
{
    glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(r, r, 1);
        drawBall(20);
    glPopMatrix();
}
void Ball::move()
{
    x += dx;
    y += dy;
    reflect(&dy, &y, (y < r - 1), r - 1);
    reflect(&dy, &y, (y > 1 - r), 1 - r);
    dy -= gravity;
    reflect(&dx, &x, (x < r - float(1200)/700), r - float(1200)/700);
    reflect(&dx, &x, (x > float(1200)/700 - r), float(1200)/700 - r);

    if (y < GRID_HEIGHT)
    {
        if (x > 0)
        {
            reflect(&dx, &x, (x < r), r);
        }
        else
        {
            reflect(&dx, &x, (x > -r), -r);
        }
        
    }
}