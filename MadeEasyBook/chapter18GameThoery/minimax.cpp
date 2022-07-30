#include<iostream>
using namespace std;
int calLog(int n){
    return (n==1)?0:1+calLog(n/2);
}

int miniMax(int depth,int index,bool maxTurn,int values[],int height){
    if(depth == height)
        return values[index];
    if(maxTurn){
        int m1 = miniMax(depth+1,index*2, false,values,height);
        int m2 = miniMax(depth+1,index*2+1,false,values,height);
        return max(m1,m2);
    }else{
        return min(miniMax(depth+1,index*2, true,values,height),
                   miniMax(depth+1,index*2+1, true,values,height)
                );
    }
}

int main(){
    int n;
    cin>>n;
    int values[n];
    for (int i = 0; i < n; ++i) {
        cin>>values[i];
    }
    int height = calLog(n);
    int result = miniMax(0,0,true,values,height);
    cout<<result<<'\n';
    return 0;
}