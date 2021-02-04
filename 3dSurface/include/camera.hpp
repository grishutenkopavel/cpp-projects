#ifndef CAMERA_HPP
#define CAMERA_HPP

typedef struct Point
{
    float x;
    float y;
} Point;

class Camera
{
private:
    int angleX;
    int angleZ;
    Point cameraPos;
    void move(float angle, float speed);
public:
    Camera();
    void moveForward(float speed);
    void moveSide(float speed);
    void demonstrate();
    void rotateCameraVertical(int degree);
    void rotateCameraHorizontal(int degree);
};


#endif