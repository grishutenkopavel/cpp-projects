#ifndef QUAD_HPP
#define QUAD_HPP

#include "object.hpp"

class Quad : public Object
{
private:
    float x_, y_, w_, h_;
    float colorVec[3];
public:
    Quad(float x, float y, float width, float height);
    void setColor(float r, float g, float b);
    void draw() override;
};


#endif