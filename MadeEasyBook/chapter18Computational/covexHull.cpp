#include<iostream>
#include<iomanip>
#include <vector>

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

bool crossProd(Point P,Point Q,Point R){
    double x1 = Q.x - P.x;
    double y1 = Q.y - P.y;
    double x2 = R.x - Q.x;
    double y2 = R.y - Q.y;
    return (x1 * y2 - x2 * y1) > 0;
}
double crossProduct(Point A,Point B,Point C){
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - A.x;
    double y2 = C.y - A.y;
    return abs(x1 * y2 - y1 * x2);
}
double areaOfConvHull(vector<Point> conHull){
    int siz = conHull.size();
    double area = 0;
    for(int i = 1;i<siz - 1;++i)
        area += crossProduct(conHull[0],conHull[i],conHull[i+1]);
    return area/2;
}

double convexHull(Coordinates cod,int n){
    vector<Point> conHull;
    int leftPoint = 0;
    for (int i = 0; i < n; ++i) {
        if(cod.points[i].x < cod.points[leftPoint].x)
            leftPoint = i;
    }
    int p = leftPoint;
    do{
        conHull.emplace_back(cod.points[p]);
        int q = (p + 1)%n;
        for (int r = 0; r < n; ++r) {
            if(crossProd(cod.points[p],cod.points[q],cod.points[r]))
                q = r;
        }
        p = q;
    }while (p != leftPoint);
//    for(Point a:conHull){
//        cout<<a.x<<","<<a.y<<"\n";
//    }
    double area = areaOfConvHull(conHull);
    return area;
}

int main(){
    int n;
    cin>>n;
    Coordinates cod(n);
    for (int i = 0; i < n; ++i) {
        cin>>cod.points[i].x;
        cin>>cod.points[i].y;
    }
    cout<<fixed<<setprecision(3)<<convexHull(cod,n)<<"\n";
    return 0;
}