/**
 * This algo finds all prime numbers between 2 to N in O(nloglogsqrt(n)).
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    //1. make a sieve
    int *sieve = new int[n];
    // here idx represents number
    //2. make sieve[1]  = 0 cant be prime as 1 is not a prime num
    sieve[1] = 0; // false = 0
    //3. make all other true (as they can be prime)
    for (int i = 2; i < n; i++)
        sieve[i] = 1;

    for (int i = 2; (long long)i * i <= n; i++)
    {
        // 4. if i is true make all multiple of i to false
        if (sieve[i] == 1)
        {
            for (long long j = i * i; j < n; j = j + i)
                sieve[j] = 0;
        }
    }

    // printing all prime
    for(int i = 0;i<n;i++)
        if (sieve[i] == 1)
            cout<<i<<" ";
    return 0;
}