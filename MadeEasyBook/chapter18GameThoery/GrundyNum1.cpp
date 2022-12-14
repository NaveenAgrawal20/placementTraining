#include<iostream>
#include <unordered_set>
using namespace std;

int callMax(unordered_set<int> mySet){
    int m = 0;
    while(mySet.find(m) != mySet.end())
        m++;
    return m;
}

int callGrundyNum(int n){
    if(n == 0)
        return 0;
    unordered_set<int> mySet{};
    for (int i = 0; i <= n-1; ++i) {
        mySet.insert(callGrundyNum(i));
    }
    return callMax(mySet);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout<<callGrundyNum(n)<<'\n';
    }
    return 0;
}