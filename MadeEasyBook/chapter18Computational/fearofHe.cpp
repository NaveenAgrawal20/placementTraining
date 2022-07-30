#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() {
    fio;
    int t;
    cin >> t;
    while (t--) {
        double ha, hb, hc;
        cin >> ha >> hb >> hc;
        if (ha == 0 || hb == 0 || hc == 0) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        ha = 1/ha;
        hb = 1/hb;
        hc = 1/hc;
        double h = (ha+hb+hc);
        double a = (-ha+hb+hc);
        double b = (ha-hb+hc);
        double c = (ha+hb-hc);
        if(h <= 0 || a<=0 || b<=0 ||c <= 0 ){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        double area = sqrt(h*a*b*c);
        area = 1/area;
        cout<<fixed<<setprecision(3)<<area<<"\n";
    }
    return 0;
}
/*
4
31.573 22.352 63.448
5.710 25.635 32.805
46.300 50.868 86.683
22.005 24.725 22.914
*/