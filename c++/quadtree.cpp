#include "quadtree.h"

quadtree::quadtree()
{
}

quadtree::quadtree(boxes b, string id_)
{
    boundary = b;
    id = id_;
}


void quadtree::print_info()
{
    cout<<"Quad ID: "<<this->id<<endl;
    cout<<"Boundary info:\n";
    this->boundary.print_info();
    cout<<"Contained points: "<<this->points.size()<<endl;
    cout<<"Has subquads-->";
    if(this->sub_quadrant.size() == 0)
    {
        cout<<"NO\n";
        cout<<endl;
    }
    else if(this->sub_quadrant.size() == 4)
    {
        cout<<"YES\n";
        cout<<endl;
        for(int i = 0; i<this->sub_quadrant.size(); i++)
        {
            this->sub_quadrant[i].print_info();
        }
    }
    else
    {
        cout<<"Something strange..\n";
        cout<<"Size of subquadrants: "<<this->sub_quadrant.size()<<endl;
    }
    
}

void quadtree::subdivide()
{
    //here we also divide the points contained by parent quadrant (not at the moment)
    //the order of the sub quadrants start from the top left and goes clockwise

    vector<float> parent_coord = this->boundary.get_coord();
    vector<float> parent_sides = this->boundary.get_sides();
    float new_side_x = parent_sides[0]/2.;
    float new_side_y = parent_sides[1]/2.;

    this->sub_quadrant.push_back(quadtree(boxes(parent_coord[0],
                                                parent_coord[1],
                                                new_side_x,
                                                new_side_y),
                                                this->id + string("0")));

    this->sub_quadrant.push_back(quadtree(boxes(parent_coord[0] + new_side_x,
                                                parent_coord[1],
                                                new_side_x,
                                                new_side_y),
                                                this->id + string("1")));

    this->sub_quadrant.push_back(quadtree(boxes(parent_coord[0] + new_side_x,
                                                parent_coord[1] + new_side_y,
                                                new_side_x,
                                                new_side_y),
                                                this->id + string("2")));

    this->sub_quadrant.push_back(quadtree(boxes(parent_coord[0],
                                                parent_coord[1] + new_side_y,
                                                new_side_x,
                                                new_side_y),
                                                this->id + string("3")));
    
    
    /*for(int i = 0; i<this->points.size(); i++)
    {
        if(this->sub_quadrant[0].insert_point(this->points[i])) continue;
        if(this->sub_quadrant[1].insert_point(this->points[i])) continue;
        if(this->sub_quadrant[2].insert_point(this->points[i])) continue;
        if(this->sub_quadrant[3].insert_point(this->points[i])) continue;
    }*/
}

bool quadtree::insert_point(point_data p)
{
    //check if the point is inside the boundary of the current quadrant, if it is proceed with insertion
    if(!this->boundary.check_point(p))
    {
        return false;
    }
    //if there is space insert the point here
    else if(this->points.size() < this->capacity && this->sub_quadrant.size() == 0)
    {
        this->points.push_back(p);
        return true;
    }
    //otherwise subdivide the quadrant and insert the point in the correct subquadrant
    else if (this->points.size() == this->capacity)
    {
        if (this->sub_quadrant.size() == 0)
        {
            this->subdivide();
        }
        if(this->sub_quadrant[0].insert_point(p)) return true;
        if(this->sub_quadrant[1].insert_point(p)) return true;
        if(this->sub_quadrant[2].insert_point(p)) return true;
        if(this->sub_quadrant[3].insert_point(p)) return true;
        else
        {
            printf("Something in the subquadrant is wrong\n");
            return false;
        }
        
    }
    else
    {
        printf("Something Wrong!!\n");
        return false;
    }
}

vector<point_data> quadtree::queryRange(boxes range)
{
    vector<point_data> range_points;
    if(!this->boundary.check_intersection(range))
    {
        //cout<<this->id<<"---->NO INTERSECTIONS\n";
        return range_points;
    }

    for(int i = 0; i<this->points.size(); i++)
    {
        if(range.check_point(this->points[i]))
        {
            range_points.push_back(this->points[i]);
        }
    }
    if(this->sub_quadrant.size() == 4)
    {
        vector<point_data> tmp;
        tmp = this->sub_quadrant[0].queryRange(range);
        range_points.insert(range_points.end(), tmp.begin(), tmp.end());
        tmp.clear();

        tmp = this->sub_quadrant[1].queryRange(range);
        range_points.insert(range_points.end(), tmp.begin(), tmp.end());
        tmp.clear();

        tmp = this->sub_quadrant[2].queryRange(range);
        range_points.insert(range_points.end(), tmp.begin(), tmp.end());
        tmp.clear();

        tmp = this->sub_quadrant[3].queryRange(range);
        range_points.insert(range_points.end(), tmp.begin(), tmp.end());
    }
    return range_points;
}


vector<point_data> quadtree::get_points()
{
    vector<point_data> tmp;
    tmp.insert(tmp.end(), this->points.begin(), this->points.end());

    if(this->sub_quadrant.size() == 4)
    {
        vector<point_data> tmp2;
        tmp2 = this->sub_quadrant[0].get_points();
        tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
        tmp2.clear();

        tmp2 = this->sub_quadrant[1].get_points();
        tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
        tmp2.clear();

        tmp2 = this->sub_quadrant[2].get_points();
        tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
        tmp2.clear();

        tmp2 = this->sub_quadrant[3].get_points();
        tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
    }

    return tmp;
}