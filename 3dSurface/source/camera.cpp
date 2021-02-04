#include <GL/gl.h>
#include "../include/camera.hpp"
#include <math.h>
Camera::Camera()
    :
    angleX(20),
    angleZ(0),
    cameraPos({0, 0}) {}

void Camera::demonstrate()
{
    glRotatef(-angleX, 1, 0, 0);
    glRotatef(-angleZ, 0, 0, 1);
    glTranslatef(-cameraPos.x, -cameraPos.y, -3);
}

void Camera::move(float angle, float speed)
{
    if(speed)
    {
        cameraPos.x += sin(angle) * speed;
        cameraPos.y += cos(angle) * speed;
    }
}
void Camera::moveForward(float speed)
{
    move(-float(angleZ) / 180 * M_PI, speed);
}

void Camera::moveSide(float speed)
{
    if(speed < 0)
        move((-float(angleZ) / 180 * M_PI) - (M_PI * 0.5), -speed);
    if(speed > 0)
        move((-float(angleZ) / 180 * M_PI) + (M_PI * 0.5), speed);
}

void Camera::rotateCameraVertical(int degree)
{
    angleX += degree;
    if(angleX > 180)
        angleX = 180;
    if(angleX < 0)
        angleX = 0;
}
void Camera::rotateCameraHorizontal(int degree)
{
    angleZ += degree;
}