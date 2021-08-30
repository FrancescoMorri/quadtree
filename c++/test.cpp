#include "boxes.cpp"


int main(){
    boxes a = boxes(0, 0, 1, 1);
    boxes b = boxes(0, 1, 1, 1);
    point_data alpha = point_data(0.5, 0.5);
    point_data beta = point_data(1.5, 1.5);
    //a.print_info();
    b.print_info();
    if(a.check_intersection(alpha, beta))
    {
        printf("Box a intersects\n");
    }
    if(b.check_intersection(alpha, beta))
    {
        printf("Box b intersects\n");
    }
}
