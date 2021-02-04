#ifndef CUBE_HPP
#define CUBE_HPP

#include <GL/gl.h>
#include "object.hpp"

class Cube : public Object
{
private:
    /* data */
public:
    void draw() override;
};


#endif