// #include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int i;
//         string tabCard, playerCard[5];
//         cin >> tabCard;
//         for (i = 0; i < 5; i++)
//             cin >> playerCard[i];

//         for (i = 0; i < 5; i++)
//         {
//             if (playerCard[i][0] == tabCard[0] || playerCard[i][1] == tabCard[1])
//             {
//                 cout << "YES"
//                      << "\n";
//                 break;
//             }
//         }
//         if (i == 5)
//             cout << "NO" << "\n";
//     }
//     return 0;
// }


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
        int i,flag = 0;
        string tabCard,playerCard;
        cin>>tabCard;
        for(i = 1;i<=5;i++)
		{
            cin>>playerCard;
            if(playerCard[0] == tabCard[0] || playerCard[1] == tabCard[1])
                flag = 1;
        }
        if(flag)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }

    return 0;
}
/*
3
AS
2H 4C TH JH AD
2H
3D 4C AC KD AS
4D
AS AC AD AH 5H
YES
NO
YES
9
7H
TC 4C KC AD 9S
KH
3C QD 9S KS 8D
4H
JH QC 5H 9H KD
9H
KC 6D KD 4C 2S
AD
QC 5S 4H JH 2S
7S
2H 4H 5H 6H 2S
AC
2D 3D 4D 5C 6D
2S
2H 3H 4H 5H 6H
9D
2D 3D 4D 5D 6D
NO
YES
YES
NO
NO
YES
YES
YES
YES
*/
