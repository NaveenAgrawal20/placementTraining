#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int t;

	cin >> t;

	while(t--){
		int n,m; cin >> n >> m;

		int l = n / 2;

		if(n % 2 != 0){
			for (int i = m - l; i < m + l + 1; i++){
				cout << i << " ";
			}
		}
		else{
			for (int i = m - l; i < m + l + 1; i++){
				if (i != m)
					cout << i << " ";
			}	
		}
		cout << "\n"; 	
	}
}
/*
5
6 2
3 7
5 1
1 10
6 10
*/