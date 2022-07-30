#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int D,d,a,b,c,prize = 0;
        cin>>D>>d>>a>>b>>c;
        int dis = D*d;
        if(dis >= 10)
            prize = a;
        if(dis >= 21)
            prize = b;
        if(dis >= 42)
            prize = c;
        cout<<prize<<"\n";
    }
    return 0;
}
/*
3
1 1 1 2 3
10 1 1 2 3
10 3 1 2 3
*/