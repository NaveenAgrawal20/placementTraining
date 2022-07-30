#include <iostream>
#include <vector>
#define endl "\n"
#define MAX 1000005

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool sieve[MAX];
    sieve[1] = false;
    for (int i = 2; i < MAX; i++)
        sieve[i] = true;

    for (int i = 2; i * i < MAX; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j < MAX; j = j + i)
                sieve[j] = false;
        }
    }
    vector<int> primes;
    for(int i = 2;i < MAX;i++)
    {
        if(sieve[i] == true)
            primes.push_back(i);
    }

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << primes[n - 1] << endl;
    }

    return 0;
}
