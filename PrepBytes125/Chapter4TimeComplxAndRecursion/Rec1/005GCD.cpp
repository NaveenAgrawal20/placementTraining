#include <iostream>
#include <string>
#define endl "\n";
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int T;
   cin >> T;
   while (T--)
   {
       int a,b;
       cin >> a >> b;
       cout<<gcd(a,b)<<endl;
   }
   return 0;
}
