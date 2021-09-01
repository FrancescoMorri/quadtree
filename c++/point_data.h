#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class point_data
{
private:
    vector<float> coords;
public:
    point_data();
    point_data(float x_, float y_);
    vector<float> get_coord();
};
