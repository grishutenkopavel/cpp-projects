#ifndef BALL_HPP
#define BALL_HPP
class Ball{
    public:
        float x, y;
        float dx, dy;
        float r;
        Ball(float x, float y, float dx, float dy, float r);
        void render(int cnt);
};
#endif