#include "boxes.h"

boxes::boxes(double x_, double y_, float side_){
    x = x_;
    y = y_;
    side = side_;
}

void boxes::print_info(){
    cout<<this->x<<" "<<this->y<<" "<<this->side<<endl;
}

bool boxes::check_point(float px, float py){
    float left_x = this->x;
    float left_y = this->y;
    float size = this->side;
    if ((px > left_x || px < left_x + size) && (py > left_y || py < left_y + size))
    {
        return true;
    }
    else
    {
        return false;
    }
}
