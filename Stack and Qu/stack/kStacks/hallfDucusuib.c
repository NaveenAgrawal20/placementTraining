#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int arr[SIZE];
int top1 = SIZE/2+1, top2 = SIZE/2;

void pushinS1(int k)
{
    if(top1 <= 0) // as we fill it reverse.
    {
        printf("STACK 1 OVERFLOW");
        return;
    }
    top1--;
    arr[top1] = k;
}

void pushinS2(int k)
{
    if(top2 >= SIZE-1) // as we fill it reverse.
    {
        printf("STACK 2 OVERFLOW");
        return;
    }
    top2++;
    arr[top2] = k;
}

int pop1()
{
    if(top1 >= SIZE/2+1 ){
        printf("EMPTY 1");
        return -999;
    }
    int x = arr[top1];
    top1++;
    return x;
}
int pop2()
{
    if(top2 <= SIZE/2  ){
        printf("EMPTY 1");
        return -999;
    }
    int x = arr[top2];
    top2--;
    return x;
}
////////////////////////////
int main()
{
    pushinS1(10);
    pushinS1(30);
    pushinS1(100);
    pushinS1(50);
    pushinS2(90);
    pushinS2(180);
    return 0;
}