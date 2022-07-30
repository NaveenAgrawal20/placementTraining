#include<iostream>
using namespace std;

int main(){
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double A1 = y2 - y1;
    double B1 = x1 - x2;
    double C1 = A1 * x1 + B1 * y1;
    cout<<A1<<"x + "<<B1<<"y = "<<C1<<endl;

    // D1C -B1D1X1 + A1D1Y1 = D
    double D1X1 = (x1+x2)/2;
    double D1Y1 = (y1+y2)/2;
    double D1 = -B1 * D1X1 + A1 * D1Y1;
    cout<<D1<<endl;
    // Line 2
    cin>>x1>>y1>>x2>>y2;
    double A2 = y2 - y1;
    double B2 = x1 - x2;
    double C2 = A2 * x1 + B2 * y1;

    cout<<A2<<"x + "<<B2<<"y = "<<C2<<endl;

    // D2C
    double D2X1 = (x1+x2)/2;
    double D2Y1 = (y1+y2)/2;
    double D2 = -B2 * D2X1 + A2 * D2Y1;
    cout<<D2<<endl;
    // intersecton
    double det = -B1 * A2 - A1 * - B2;
    if(det == 0)
        cout<<"Lines are parallel No Intesection\n";
    else{
        double cenX = (A2 * D1 - A1 * D2)/det;
        double cenY = (B2 * D1 - B1 * D2)/det;
        cout<<cenX<<","<<cenY<<"\n";
    }
    return 0;
}
/*
-3 5 3 3
3 3 11 19*/