#include <iostream>
using namespace std;

int main(){
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    double A1 = y2 - y1;
    double B1 = x1 - x2;
    double C1 = A1 * x1 + B1 * y1;

    // line 2
    cin>>x1>>y1>>x2>>y2;
    double A2 = y2 - y1;
    double B2 = x1 - x2;
    double C2 = A2 * x1 + B2 * y1;

    // line intesection
    double det = A1 * B2 - A2 * B1;
    if(det == 0)
        cout<<"Lines are parallel No Intesection\n";
    else
    {
        double x = (B2*C1 - B1*C2)/det;
        double y = -1 * (A2*C1 - A1*C2)/det;
        cout<<"Intersection Points = ("<<x<<","<<y<<")\n";
        /* for line segments  Take input for if user wants intersection for line Segments
        if(isLineSeg && (x >=  min(x1,x2) && x <= max(x1,x2)) && (y >= min(y1 , y2) && y <= max(y1,y2)))
            cout<<"Intersection Points = ("<<x<<","<<y<<")\n";
        else
            cout<<"For Line segments and no intersection\n";
        */
    }

    return 0;
}
/*
-5 3 0 -7
2 3 -1 3
*/