#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point{
public:
     double x,y;
};

class Coordinates{
public:
    Point *points;
    Coordinates(int coordinates){
        points = new Point[coordinates];
    }
};

double crossProduct(Point A,Point B,Point C){
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - A.x;
    double y2 = C.y - A.y;
    return abs(x1 * y2 - y1 * x2);
}
double dotProduct(Point A, Point B,Point C){
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - A.x;
    double y2 = C.y - A.y;
    return abs(x1 * y1 + x2 * y2);
}
double distance(Point A, Point B){
    double d1 = B.x - A.x;
    double d2 = B.y - A.y;
    return sqrt(d1*d1 + d2 * d2);
}
double linePointDistance(Coordinates cod, bool isLineSegment){
    double dist = crossProduct(cod.points[0],cod.points[1],cod.points[2]);
    dist /= distance(cod.points[0],cod.points[1]);
    if(isLineSegment){
        double dot1 = dotProduct(cod.points[0],cod.points[1],cod.points[2]);
        if(dot1 > 0)
            return abs(distance(cod.points[1],cod.points[2]));
        double dot2 = dotProduct(cod.points[1],cod.points[0],cod.points[2]);
        if(dot2 > 0)
            return abs(distance(cod.points[0],cod.points[2]));
    }
    return abs(dist);
}
double areaOfPolygon(Coordinates cod,int n){
    double area = 0;
    for(int i = 1;i<n-1;i++){
        area += crossProduct(cod.points[0],cod.points[i],cod.points[i+1]);
    }
    return abs(area/2);
}
double perimeter(Coordinates cod,int n){
    double per = 0;
    per += distance(cod.points[0],cod.points[n-1]);
    for (int i = 0; i < n-1; ++i) {
        per += distance(cod.points[i],cod.points[i+1]);
    }
    return per;
}
int main(){
    int n;
    cin>>n;
    Coordinates cod(n);
    for (int i = 0; i < n; ++i) {
        cin>>cod.points[i].x;
        cin>>cod.points[i].y;
    }
    cout<<"Line Distance = "<<linePointDistance(cod,false)<<"\n";
    cout<<"Line Distance = "<<linePointDistance(cod,true)<<"\n";
    cout<<fixed<<setprecision(3)<<perimeter(cod,n);
    return 0;
}