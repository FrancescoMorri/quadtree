#include <iostream>

using namespace std;

class boxes
{
    private:
        double x, y;
        float side;
    public:
        boxes(double x_, double y_, float side_);
        void print_info();
        bool check_point(float px, float py);
};