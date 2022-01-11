# quadTree
The aim of this repo is to build a basic class implementing the quadtree algorithm in different languages (C++, Python and JavaScript for now). The class should work as a blank canvas upon which one can build and implement everything needed, in this sense is not built with a specific aim in mind.


The basic idea behind this algorithm and how it works are well described [here](https://en.wikipedia.org/wiki/Quadtree), so I will not explain it further.

## C++ Class
There are two helper classes: `boxes` and `point_data`.
### `point_data`
This class simply implements bidimensional coordinates, that are usefule for the whole program.

### `boxes`
Everything is based of squares, so to make everything cleaner we will use this simple class. The only two interesting methods are:
+ `check_point` : checks the intersection with a point
+ `check_intersection`: checks if two boxes are overlapped

Other than that in both classed there are methods to access the coordinates of the points and the boxes.

The actual algorithm is implemented in `quadtree`.
### `quadtree`
Each quadtree has four attributes:
+ `boundary`: the dimension of the quadrant
+ `id`: its name, useful to track recursion
+ `points`: the points contained in the quadrant
+ `sub_quadrant`: the smaller quadrant in which this one is divided once full

For each quadrant is also defined a constant variable `capacity` which is the max number of points that can be put inside the quadrant.

The more interesting part is in the methods of the class:
+ `insert_point`: this method insert a point in the quadrant. It firstly check if it is inside, and if the quadrant can accept more points it is inserted in the vector `points`. If the quadrant is full it checks whether is already subdivided or not, if it is not we subdivide it. Then `insert_point` is recursively called on the smaller subquadrants. If it was already subdivided, we directly call the method recursively.
+ `subdivide`: this method simply split the quadrant in four smaller parts. For now the points of the bigger quadrant


## Python Class
`TO DO`

## JavaScript Class
`TO DO`
