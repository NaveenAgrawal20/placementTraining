#include <bits/stdc++.h>
using namespace std;

int maxDiff(int x[],int n)
{
    // a = a + i;
    // b = b - i;
    int a[n],b[n],i,ans1,ans2;

    for(i = 0;i<n;i++){
        a[i] = x[i] + i;
        b[i] = x[i] - i;
    }
    int maxd = a[0] ,mind = a[0] ;
    // for a
    for(i = 0;i<n;i++)
    {
        maxd = max(maxd,a[i]);
        mind = min(mind,a[i]);
    }
    ans1 = maxd - mind;
    // for b
    maxd = b[0] ,mind = b[0];
    for(i = 0;i<n;i++)
    {
        maxd = max(maxd,b[i]);
        mind = min(mind,b[i]);
    }
    ans2 = maxd - mind;
    return max(ans1,ans2);

}

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        int n,i;
        cin>>n;
        int x[n];
        for(i = 0;i<n;i++)
            cin>>x[i];
        cout<<maxDiff(x,n)<<"\n";
    }
    return 0;
}
/*
10
4
2 3 4 2
4
2 1 4 2
3
2 2 2
2
2 2
1
2
6
15 3 7 19 13 16
6
10 5 15 18 11 4
6
2 17 13 15 6 18
6
6 16 17 6 19 4
6
16 19 19 4 16 18
*/
