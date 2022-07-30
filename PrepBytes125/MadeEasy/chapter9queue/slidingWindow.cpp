#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    int n = 8;
//    int a[n] = {1,3,-1,-3,5,3,6,7};
    cin>>n;
    int *a = new int[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    // solution
    int w = 3;
    cin>>w;
    for(int i = 0;i<w;i++){
        while(!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    int *b = new int[n - w + 1];
    for(int i = w;i<n;i++){
        b[i - w] = a[dq.front()];

        while(!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();
        while(!dq.empty() &&  i - dq.front() >= w)
            dq.pop_front();
        dq.push_back(i);
    }
    b[n-w] = a[dq.front()];
    for(int i = 0;i<n-w+1;i++)
        cout<<b[i]<<" ";
    return 0;
}
//8
//1 3 -1 -3 5 3 6 7
//3