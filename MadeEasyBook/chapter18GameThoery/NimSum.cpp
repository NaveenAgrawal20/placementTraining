#include<iostream>

int calculateNimSum(int pile[], int n){
    int nimSum = pile[0];
    for (int i = 1; i < n; ++i) {
        nimSum ^= pile[i];
    }
    return nimSum;
}

using namespace std;

int main(){
    int n;
    cin>>n;
    int pile[n];
    for (int i = 0; i < n; ++i) {
        cin>>pile[i];
    }
    char playerFirst;
    cin>>playerFirst;
    int nimSum = calculateNimSum(pile,n);
    if(nimSum == 0){
        if(playerFirst == 'A'){
            cout<<"Player B is winner\n";
        }else {
            cout << "Player A is winner\n";
        }
    }else{
        if(playerFirst == 'A')
            cout<<"Player A is winner\n";
        else
            cout<<"Player B is winner\n";
    }
    return 0;
}
