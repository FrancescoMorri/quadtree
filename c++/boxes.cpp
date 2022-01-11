#include "boxes.h"

boxes::boxes()
{
}

boxes::boxes(float x_, float y_, float side_)
{
    x = x_;
    y = y_;
    side1 = side_;
    side2 = side_;
}

boxes::boxes(float x_, float y_, float side_1, float side_2)
{
    x = x_;
    y = y_;
    side1 = side_1;
    side2 = side_2;
}

void boxes::print_info()
{
    printf("x = %.4f\ty = %.4f\nside1 = %.4f\tside2 = %.4f\n", this->x, this->y, this->side1, this->side2); 
}

bool boxes::check_point(point_data p)
{
    float left_x = this->x;
    float left_y = this->y;
    float x_size = this->side1;
    float y_size = this->side2;
    if ((p.get_coord()[0] > left_x && p.get_coord()[0] < left_x + x_size) &&
     (p.get_coord()[1] > left_y && p.get_coord()[1] < left_y + y_size))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool boxes::check_intersection(boxes range)
{
    float A_up_x = this->x;
    float A_up_y = this->y;
    float A_down_x = this->x + this->side1;
    float A_down_y = this->y + this->side2;

    float B_up_x = range.get_coord()[0];
    float B_up_y = range.get_coord()[1];
    float B_down_x = range.get_coord()[0] + range.get_sides()[0];
    float B_down_y = range.get_coord()[1] + range.get_sides()[1];
    
    //if this is above range
    //if this is on the left of range
    //if range is above this
    //if range is on the left of this
    if(A_down_y < B_up_y || A_up_x > B_down_x || B_down_y < A_up_y || B_up_x > A_down_x)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

vector<float> boxes::get_coord()
{
    vector<float> coords;
    coords.push_back(this->x);
    coords.push_back(this->y);
    return coords;
}

vector<float> boxes::get_sides()
{
    vector<float> sides;
    sides.push_back(this->side1);
    sides.push_back(this->side2);
    return sides;
}