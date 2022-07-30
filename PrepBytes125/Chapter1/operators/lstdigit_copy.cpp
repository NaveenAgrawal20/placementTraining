#include<iostream>
using namespace std;
/*
In Copy Clock And Angles.
*/

int main()
{
    int t,h,m;
    cin>>t;
    float hour_angle,minute_angle;
    while(t--){
        cin>>h>>m;
        if(h == 12)
            h = 0;
        if(m == 60)
        {
            m = 0;
            h += 1;
            if(h>12){
                h-=12;
            }
        }
        hour_angle = 0.5*(60*h+m);
        minute_angle = 6.0*m;
        cout<<abs(minute_angle-hour_angle)<<"\n";
    }
    return 0;
}
