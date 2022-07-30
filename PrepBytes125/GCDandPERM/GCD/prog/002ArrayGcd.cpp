#include <iostream>
#include <limits>

using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;
	return GCD(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n,i;
        cin >> n;
        int *a = new int[n];
        for(i= 0;i<n;i++)
            cin>>a[i];

        int gcd = a[0];
        for(i = 1;i<n;i++)
            gcd = GCD(gcd,a[i]);

        int count = 0;
        for(i = 1;i*i<=gcd;i++)
        {
            if(gcd % i == 0)
            {
            	if(i*i == gcd)
            		count += 1;
            	else
					count += 2;		
                /* if gcd = 12 than factors will be(1,2,3,4,6,12) but i id from 1 to i*i <=n (i<=3)
                    that means for every i which is 1,12 2,4 3,6 but if i = i*i = 12 than that is 
                    for eg gcd = 4
                    than i = [1,2] => 1,4 and 2 as 2*2 = 4 which is already included in factors.
                */
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
/*
4
3
4 12 8
3
4 13 8
5
2 4 6 8 10
3
91 105 225
*/
