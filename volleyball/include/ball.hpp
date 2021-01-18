#ifndef BALL_HPP
#define BALL_HPP
class Ball{
    public:
        float gravity;
        float x, y;
        float dx, dy;
        float r;
        Ball(float x, float y, float dx, float dy, float r);       
        void drawBall(int cnt);
        void reflect(float *da, float *a, bool cond, float wall);
        bool isCross(float x1, float y1, float r, float x2, float y2);
        void mirror(float x, float y, float speed);
        void checkCollision(float *playerX, float *playerY, float *playerR);
        void render();
        void move();
};
#endif