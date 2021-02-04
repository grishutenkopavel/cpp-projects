#include <GL/gl.h>
#include "../include/camera.hpp"

Camera::Camera()
    :
    angleX(20),
    angleZ(0) {}

void Camera::demonstrate()
{
    glRotatef(-angleX, 1, 0, 0);
    glRotatef(-angleZ, 0, 0, 1);
    glTranslatef(0, 0, -3);
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