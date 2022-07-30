#include <iostream>
#include <vector>
#define endl "\n"
#define MAX 1000005

using namespace std;

bool isOddPrime(int n)
{
    return n == 3 || n == 5 || n == 7;
}
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
        int flag = 0;
        cin >> n;
        long long int sum = 2;
        int count = 1;
        for(int i = 3;i<primes.size();i++)
        {
            flag = 0;
            int pn = primes[i];
            while(pn != 0)
            {
                int d = pn % 10;
                pn /= 10;
                if(isOddPrime(d))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                sum += primes[i];
                count++;
                if(count == n)
                    break;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
/*
2
3
4
*/