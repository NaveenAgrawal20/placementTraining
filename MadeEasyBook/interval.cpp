#include <bits/stdc++.h>
using namespace std;
struct Interval {
    int start, end;
};

void findIntersection(Interval intervals[], int N,int m)
{
    bool flag = false;
    int l = intervals[0].start;
    int r = intervals[0].end;
    int maxL = INT_MIN;
    for (int i = 1; i < N && m != 0; i++) {
        if (intervals[i].start > r || intervals[i].end < l) {
            continue;
        }
        else {
            l = max(l, intervals[i].start);
            r = min(r, intervals[i].end);
            int currentL = r - l + 1;
            if(maxL < currentL)
            {
                flag = true;
                maxL = currentL;
                m--;
            }
        }
    }
    if(N == 1)
        cout<<r-l+1<<"\n";
    else{
        if(flag)
            cout <<maxL<<"\n";
        else
            cout<<0<<"\n";
    }
}
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N,m,i;
    cin >> N >> m;
    Interval intervals[N];
    for (i = 0; i < N; i++)
        cin >> intervals[i].start;
    for (i = 0; i < N; i++)
        cin >> intervals[i].end;
    sort(intervals, intervals + N, compareInterval);
    findIntersection(intervals, N, m);
}
/*
3
1
1
1
2
3
2
1
2
5
4
6
7
3
2
1
3
5
2
4
6
*/

