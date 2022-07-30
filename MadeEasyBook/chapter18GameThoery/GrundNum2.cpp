#include<iostream>
#include <unordered_set>
using namespace std;

int calMex(unordered_set<int> mySet)
{
    int m = 0;
    while(mySet.find(m) != mySet.end())
        m++;
    return m;
}
int calGrundyNum(int n){
    if(n <= 3)
        return n;
    unordered_set<int> myset;
    for (int i = 1; i <= 3; ++i) {
        myset.insert(calGrundyNum(n-i));
    }
    return calMex(myset);
}

int main(){
    int n;
    cin >> n;
    cout<<calGrundyNum(n)<<'\n';
    return 0;
}