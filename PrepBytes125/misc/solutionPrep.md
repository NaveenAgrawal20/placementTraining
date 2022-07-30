# 1. Array Quality question

1. The approach is to start from the left most side of the array and keep on equalising the elements in both the arrays. Because once we move ahead, our next actions will not disturb the left side of the array.
2. Initialise current and total as 0 and start traversing the array from the left.
3. for every element A[i], the absolute difference between the element and current is the number of operations required to equalise ith element of the Magical container with A[i], keep adding the absolute difference to total. Also update current with A[i].
4. Keep following the same procedure for equalising each and every element.

FROM 21 MAy

# 2. MUTLIPLY String

The length of the string is more than 19 which means the number is greater than 10^18. It can not be done with simple multiplication. Reverse the input strings.
Then try to perform multiplication same as we do on paper for multidigit numbers. Convert each digit into int for both strings.
Multiply digit by digit , store the carry and add it to next place.

# 3. MINUS PLUS String

    int main()
    {
        //write your code here
        int n;
        cin>>n;
        while(n--)
        {
        string s,t;
        cin>>s;
        cin>>t;
        int flag=0,diff=0;
        if(s.length()<t.length())
        {
            flag=1;
        }else{
            for(int i=0;i<s.length();i++){
            if(s[i]==t[i-diff])
            {
            flag=0;
            }
            else if(s[i]=='-' && s[i+1]=='-' && t[i-diff]=='+'){
            i++;
            diff++;
            }else{
            flag=1;
            break;
            }
        }
        }
        if(flag==0)
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        }
        return 0;
    }
# 4. LOVEA string

9
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
ababababababababababababababababababababababababav
abababababababababababababababababababababababava
abababababababababababababababababababababababavv
ap
dya
kvujzkexnkqygxalmlpupghpqqsvqsabpbgrhmwixfroghpm
ckhklxvduyregcmxabkrbcnxxjlgoaiikpbvuamdvrksefigx
xaxax
o/p
50
49
49
47
1
1
3
5
3


/**/
This solution uses extra space to store the last indexes of already visited characters. The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring seen so far in res. When we traverse the string, to know the length of current window we need to indexes.
1) Ending index ( j ) : We consider current index as ending index.
2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.
try to understand this

11PB_Buddy  11 hours ago
once go through this

Devesh Kumar Bhardwaj  15 minutes ago
#include <bits/stdc++.h>
using namespace std;
#define ff          first
#define ss          second
#define ll          long long
#define ld          long double
#define mod         1000000007
#define endl        "\n"
#define inf         1e18
#define w(x)        int x;cin>>x;while(x--)
  void solve(){
      //int n;cin>>n;cin.get();
      string str;cin>>str;
      int n = str.length();
      int arr[256]={-1};
      int last_index=0;
      int max_len=0;
      for (int i=0;i<n;i++){
          if(arr[str[i]]!=-1){
              last_index=  max(last_index,arr[str[i]]+1);
              arr[str[i]]=i;
          }
          else {
               arr[str[i]]=i;
          }
          int a =i- last_index;
        //  cout<<last_index<<" ";
          max_len=max(max_len,a+1);
      }
      cout<<max_len<<endl;
  }
  void t_c(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freeopen("input.txt","r",stdin);
    freeopen("output.txt","w",stdout);
    #endif
  }
  int main()
  {
      t_c(); w(t){solve();}
    return 0;
  }


Use loop and recursion skills here.
Run a loop from 1 to 9.
For each iteration make a recursion call to try every possible combination.
Draw a recursion tree first to figure out the base case.