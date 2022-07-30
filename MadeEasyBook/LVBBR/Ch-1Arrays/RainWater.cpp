#include<iostream>
using namespace std;

int maxWater(int a[], int n)
{
	int res = 0;
	int l = 0,r = n-1,lmax = 0,rmax = 0;
	while(l<=r)
    {
        if(a[l] >= a[r])
        {
            if(a[r] > rmax)
                rmax = a[r];
            else
                res += rmax - a[r];
            r--;
        }else{
            if(a[l] > lmax)
                lmax = a[l];
            else
                res += lmax - a[l];
            l++;
        }
    }

	return res;
    //  |
    // ||
    // |||
    // ||||
}

// Driver code
int main()
{
	int a1[] = {3,4,2,1};
	int a2[] = {3,0,2,1};
	int a4[] = {3,4,0,1};
    int a3[] = {1,0,3, 0, 2, 0, 4};
	
	cout << maxWater(a1, sizeof(a1)/sizeof(a1[0]))<<'\n';
	cout << maxWater(a2, sizeof(a2)/sizeof(a2[0]))<<'\n';
	cout << maxWater(a4, sizeof(a4)/sizeof(a4[0]))<<'\n';
	cout << maxWater(a3, sizeof(a3)/sizeof(a3[0]))<<'\n';
	
	return 0;
}