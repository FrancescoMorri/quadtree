#include "quadtree.cpp"


int main(){
    srand(time(NULL));
    float width = 10.;
    float height = 10.;
    int number_points = 10000;
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
    
    
    boxes range = boxes(0,0,1);
    vector<point_data> range_points;
    vector<point_data> tmp;

    tmp = starting_quad[0].queryRange(range);
    range_points.insert(range_points.end(), tmp.begin(), tmp.end());
    
    tmp = starting_quad[1].queryRange(range);
    range_points.insert(range_points.end(), tmp.begin(), tmp.end());

    tmp = starting_quad[2].queryRange(range);
    range_points.insert(range_points.end(), tmp.begin(), tmp.end());

    tmp = starting_quad[3].queryRange(range);
    range_points.insert(range_points.end(), tmp.begin(), tmp.end());

    //for(int i = 0; i<range_points.size(); i++)
    //{
    //    cout<<range_points[i].get_coord()[0]<<" "<<range_points[i].get_coord()[1]<<endl;
    //}
    cout<<"Found "<<range_points.size()<<" points in range:\n";
    range.print_info();
}
