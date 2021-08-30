#include "point_data.h"

point_data::point_data(float x_, float y_)
{
    coords[0] = x_;
    coords[1] = y_;
}

float* point_data::get_coord()
{
    return this->coords;
}
