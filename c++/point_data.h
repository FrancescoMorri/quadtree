#include <iostream>
#include <stdio.h>

using namespace std;

class point_data
{
private:
    float coords[2];
public:
    point_data();
    point_data(float x_, float y_);
    float* get_coord();
};
