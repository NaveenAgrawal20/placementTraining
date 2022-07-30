#include <iostream>
#include <vector>
#define endl "\n";
using namespace std;

vector<int> sieve(int u)
{
    int* sieve = new int[u];
    sieve[1] = 0;
    for (int i = 2; i < u; i++)
        sieve[i] = 1;
    for (int i = 2; (long long)i * i <= u; i++)
    {
        if(sieve[i] == 1)
            for(long long int j = (long long)i*i;j<u;j=j+i)
                sieve[j] = 0;
    }
    vector<int> prime;
    for (int i = 2; i < u; i++)
        if (sieve[i] == 1)
            prime.push_back(i);
    return prime;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int T;
    cin >> T;
    while (T--)
    {
        long long l, u;
        cin >> l >> u;
        vector<int> prime = sieve(sqrt(u));

        int siz = u - l + 1;
        int* arr = new int[siz];
        for (int i = 0; i < siz; i++)
            arr[i] = 1;

        for (int i = 0; i < prime.size(); i++)
        {
            for (long long j = l; j <= u; j++)
            {
                if (j == prime[i])
                    continue;
                if (j % prime[i] == 0)
                    arr[j - l] = 0;
            }
        }

        for (int i = 0; i < siz; i++)
            if (arr[i] == 1)
                cout << arr[i+l]<<" ";

    }

    return 0;
}
/*
3
1 2 3
2
5
6 1 4 2 3
3

10
10 9 8 7 6 5 4 3 2 1
1
*/