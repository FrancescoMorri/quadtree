#include "boxes.cpp"


int main(){
    boxes b = boxes(0, 0, 1.);
    b.print_info();
    float px = 0.05;
    float py = 0.05;
    cout<<b.check_point(px, py)<<endl;
}
