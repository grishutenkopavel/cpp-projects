#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera
{
private:
    int angleX;
    int angleZ;
public:
    Camera();
    void demonstrate();
    void rotateCameraVertical(int degree);
    void rotateCameraHorizontal(int degree);
};


#endif