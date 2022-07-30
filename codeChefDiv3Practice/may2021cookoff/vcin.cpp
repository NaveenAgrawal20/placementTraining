#include<iostream>
using namespace std;

typedef long long int ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
	{
		ll group,p,x[10],sum=0,maxi,mini;
		cin>>group>>p;
		for(ll i=0;i<10;i++)
		{
			cin>>x[i];
		}
		for(ll i=9;i>=group;i--)
		{
			sum+=x[i];
		}
		mini=sum/p+1;
		ll sum1=sum+x[group-1];
		maxi=sum1/p;
		if(sum1%p>0)
		{
			maxi++;
		}
		cout<<mini<<" "<<maxi<<endl;
	}
}