#include<iostream>
using namespace std;

class Point{
public:
    double x,y;
};

class Line{
public:
    Point *points;
    Line (int coordinates){
       points = new Point[coordinates];
    }
};

int dotProduct(Point A,Point B,Point C){
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - A.x;
    double y2 = C.y - A.y;
    return abs(x1 * y1 + x2 * y2);
}
int crossProduct(Point A,Point B,Point C){
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - A.x;
    double y2 = C.y - A.y;
    return abs(x1 * y2 - x2 * y1);
}

int main(){
    int n;
    cin>>n;
    Line line(n);
    for (int i = 0; i < n; ++i) {
        cin>>line.points[i].x;
        cin>>line.points[i].y;
    }
    cout<<"Dot Product = "<<dotProduct(line.points[0],line.points[1],line.points[2])<<"\n";
    cout<<"Cross Product = "<<crossProduct(line.points[0],line.points[1],line.points[2])<<"\n";
    return 0;
}
/*
3
2 4
6 3
10 15
 */