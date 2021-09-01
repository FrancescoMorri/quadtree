#include "quadtree.cpp"


int main(){
    srand(time(NULL));
    float width = 10.;
    float height = 10.;
    int number_points = 50;
    vector<point_data> points;
    for(int i = 0; i < number_points; i++)
    {
        float x = (float(rand())/RAND_MAX)*width;
        float y = (float(rand())/RAND_MAX)*height;
        points.push_back(point_data(x, y));
    }
    
    vector<quadtree> starting_quad;
    starting_quad.push_back(quadtree(boxes(0,0,width/2.,height/2.), string("0")));
    starting_quad.push_back(quadtree(boxes(width/2.,0,width/2.,height/2.), string("1")));
    starting_quad.push_back(quadtree(boxes(width/2.,height/2.,width/2.,height/2.), string("2")));
    starting_quad.push_back(quadtree(boxes(0,height/2.,width/2.,height/2.), string("3")));
        
    
    for(int i = 0; i<number_points; i++)
    {
        starting_quad[0].insert_point(points[i]);
        starting_quad[1].insert_point(points[i]);
        starting_quad[2].insert_point(points[i]);
        starting_quad[3].insert_point(points[i]);
    }
    
    starting_quad[0].print_info();
    cout<<"--------------------------------------------------------------\n\n";
    starting_quad[1].print_info();
    cout<<"--------------------------------------------------------------\n\n";
    starting_quad[2].print_info();
    cout<<"--------------------------------------------------------------\n\n";
    starting_quad[3].print_info();
    cout<<"--------------------------------------------------------------\n\n";
}
