#ifndef BALL_HPP
#define BALL_HPP
class Ball{
    private:
        void drawBall(int cnt);
        void reflect(float *da, float *a, bool cond, float wall);
    public:
        float gravity;
        float x, y;
        float dx, dy;
        float r;
        Ball(float x, float y, float dx, float dy, float r);       
        void render();
        void move();
};
#endif