#include <GL/gl.h>
#include "../include/camera.hpp"

void Camera::move()
{
    glRotatef(-20, 1, 0, 0);
    glTranslatef(0, 0, -3);
}