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

bool boxes::check_intersection(point_data left_corner, point_data right_corner)
{
    boxes range = boxes(left_corner.get_coord()[0], left_corner.get_coord()[1],
                        right_corner.get_coord()[0] - left_corner.get_coord()[0],
                        right_corner.get_coord()[1] - left_corner.get_coord()[1]);
    point_data up_left = point_data(this->x, this->y);
    point_data down_left = point_data(this->x, this->y + this->side2);
    point_data down_right = point_data(this->x + this->side1, this->y + this->side2);
    point_data up_right = point_data(this->x + this->side1, this->y);
    if(range.check_point(up_left) || range.check_point(down_left) || range.check_point(down_right) || range.check_point(up_right))
    {
        return true;
    }
    else
    {
        return false;
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