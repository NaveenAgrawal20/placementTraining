#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n = 0, a = 0,i;
        string str;
        cin >> str;
        for(i = 0;str[i] != '\0';i++)
        {
            n++;
            if(str[i] == 'a')
                a++;
        }
        if(2 * a <= n)
            cout<<(2*a - 1)<<"\n";
        else
            cout<<n<<"\n";
    }

    return 0;
}
/*
4
a
ab
bab
aabb
aababbcd
aababbcda
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
*/