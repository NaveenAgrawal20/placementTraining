#include <bits/stdc++.h>
using namespace std;
/*
Increment by powers of 3 till strictly greater than n.
Now decrement till we are close.
For 46, we go till 121 (1+3+9+27+81) , then we reduce (121-27-9-3-1=81)
N can be greater, so try to use multiplication instead of an in-built power function.
Use the variables appropriately as per the constraints.
*/
/*
Warning Take constraints into Consideration. 
*/

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int n,sum = 1,p = 3;
        cin >> n;
        while (sum < n)
        {
            sum += p;
            p  = p * 3;
        }
        
        while(p)
        {
            if(sum - p >= n){
                sum -= p;
            }
            p/=3; // 27,9 ... 
        }
        cout<<sum<<endl;
    }
    return 0;
}