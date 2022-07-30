#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<ll,vector<ll>,greater<>> pq;
        for(ll i = 0;i<n;i++)
            pq.push(arr[i]);
        
        ll cost = 0;
        while(pq.size() != 1)
        {
            ll min1 = pq.top();pq.pop();
            ll min2 = pq.top();pq.pop();

            cost += min1+min2;
            pq.push(min1+min2);
        }
        return cost;
    }
    
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends