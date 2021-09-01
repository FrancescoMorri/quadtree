#include "boxes.cpp"

class quadtree
{
    private:
        const int capacity = 4;
        string id;
        boxes boundary;
        vector<point_data> points;
        vector<quadtree> sub_quadrant;
    public:

        quadtree();
        quadtree(boxes b, string id_);
        void print_info();
        bool insert_point(point_data p);
        void subdivide();
};
