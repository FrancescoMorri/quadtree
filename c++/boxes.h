#include "point_data.cpp"

/*
The coordinates of the box are the top left corner, then the side is specified.
*/

class boxes
{
    private:
        float x, y;
        float side1, side2;
    public:
        boxes();
        boxes(float x_, float y_, float side_);
        boxes(float x_, float y_, float side_1, float side_2);
        void print_info();
        bool check_point(point_data p);
        bool check_intersection(point_data left_corner, point_data right_corner);
        vector<float> get_coord();
        vector<float> get_sides();
};