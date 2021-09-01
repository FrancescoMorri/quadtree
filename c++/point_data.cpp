#include "point_data.h"

point_data::point_data()
{
}

point_data::point_data(float x_, float y_)
{
    coords.push_back(x_);
    coords.push_back(y_);
}

vector<float> point_data::get_coord()
{
    return this->coords;
}
