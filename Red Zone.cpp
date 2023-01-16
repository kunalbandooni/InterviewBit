// Imagine the points as radiating circles, circle radius r is number of days that have passed
// as soon as B circles intersect each other at xth day, that xth day is our answer

// Brute Force - select B points from N points and keep increasing there radius(r), till all B points Eucaldian distance d 
// with one another is less than radius + radius(2*r), repeat this process, answer is minimum number of radius that satisfies this condition

// Time Complexity - choose b from n * choose 2 from B * max(distance between two choosen point/2)
// Which is O(n!*B^2*INT_MAX) in the worst case

// Optimized - Lower bound Binary Search radius r from 1 to INT_MAX, check if r gives sufficiant expansion so that 
// any two points eucaldian distance d <= r+r, if so, let the intersected area be X, check if every other point with a radius
// of r can reach this area X, if yes, increase the count, keep max count for r and if max count of r >= B that means r has
// sufficiant given sufficiant radial expansion
// Time Complexity O(n^3*log(INT_MAX))

// But how to we keep track of this Area X i.e intersection of 2 circles and check if point lies between them ?
// refer to this article: https://stackoverflow.com/questions/3349125/circle-circle-intersection-points#:~:text=The%20following%20note%20describes%20how,P1%20%2D%20P0%7C%7C.
// here a = d/2, so h = r^2 - d^2/4
// Px1 = midx - (y1-y0)h/d  Px2 = midx + (y1-y0)h/d
// Py1 = midy + (x1-x0)h/d  Py2 = midy - (x1-x0)h/d
// whatever be the order of the points, p1 and p2 get switched accordingly
// Eucaldian distance between (P1,Point) <= r for r to reach it, similarly for (P2,Point) <= r,
// if point with r is able to reach P1, count 1 gets increased, if able to reach P2 count 2 gets increased, if able to reach
// both, then both count 1 and count 2 will increase


// function for Eucaldian Distance
double dist(double x1,double x2,double y1,double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
