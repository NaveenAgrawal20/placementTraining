#include <iostream>
using namespace std;
/*
Factor of a number 
*/
void print(int n, int i)
{
    if (n == 1)
        return;
    if (i == 1)
    {
        printf("1 ");
        i++;
    }
    while (n % i != 0)
        i++;
    if (n % i == 0)
        printf("%d ", i);
    print(n / i, i);
}

int main()
{
    cout << "dasdas\n";
    print(8, 1);
    return 0;
}