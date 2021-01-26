#ifndef QUAD_HPP
#define QUAD_HPP

#include "object.hpp"

class Quad : public Object
{
private:
    float x_, y_, w_, h_;
public:
    Quad(float x, float y, float width, float height);
    void draw() override;
};


#endif