#include <bits/stdc++.h>
using namespace std;

// An interval has a start
// time and end time
struct Interval
{
    int start, end;
};

// Compares two intervals
// according to staring times.
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.end < i2.end);
}

int main()
{
    Interval arr[] = {{1, 3}, {2, 2}, {3, 1}};
    int n = 3,trucksize = 4;

    // sort the intervals in increasing order of
    // start time
    sort(arr, arr + n, compareInterval);
    int i = 0,sum = 0;
    while(trucksize && i < n)
    {
        sum += min()
    }
    cout<<sum<<endl;
    return 0;
}