#include "point_data.cpp"

/*
The coordinates of the box are the top left corner, then the side is specified.
*/

class boxes
{
    private:
        double x, y;
        float side1, side2;
    public:
        boxes();
        boxes(double x_, double y_, float side_);
        boxes(double x_, double y_, float side_1, float side_2);
        void print_info();
        bool check_point(point_data p);
        bool check_intersection(point_data left_corner, point_data right_corner);
};