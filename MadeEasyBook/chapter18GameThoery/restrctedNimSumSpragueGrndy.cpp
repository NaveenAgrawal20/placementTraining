#include<iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>

using namespace std;
int calMex(unordered_set<int> mySet)
{
    int m = 0;
    while(mySet.find(m) != mySet.end())
        m++;
    return m;
}
int calGrundyNum(int n,int grundyNum[]){
    if(n <= 3)
        grundyNum[n] = n;
    if(grundyNum[n] != -1)
        return grundyNum[n];
    unordered_set<int> mySet;
    for (int i = 1; i <= 3; ++i) {
        mySet.insert(calGrundyNum(n-i,grundyNum));
    }
    grundyNum[n] = calMex(mySet);
    return grundyNum[n];
}

int main(){
    int n;
    cin>>n;
    int pile[n];
    for(int i = 0;i<n;i++)
        cin>>pile[i];
    int max = *max_element(pile,pile+n);
    int grundyNum[max+1];
    memset(grundyNum,-1, sizeof(grundyNum));
    for (int i = 0; i < n; ++i) {
        calGrundyNum(pile[i],grundyNum);
    }
    int nimSum = grundyNum[0];
    for (int i = 1; i < n; ++i) {
        nimSum ^= grundyNum[pile[i]];
    }
    char playerF;
    cin>>playerF;
    if(nimSum == 0){
        if(playerF == 'A'){
            cout<<"B will win\n";
        }else
            cout<<"A will win\n";
    }else{
        if(playerF == 'A'){
            cout<<"A will win\n";
        }else
            cout<<"B will win\n";
    }
    return 0;
}

/*
3
4 5 6
A
OUTPUT = A will win
 */
