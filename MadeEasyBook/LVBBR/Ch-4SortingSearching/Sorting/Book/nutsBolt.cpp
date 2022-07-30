#include<iostream>
using namespace std;

void printArray(char arr[])
{
    for(int i = 0; i < 6; i++)
    {
        cout << " " <<  arr[i];
    }
    cout << "\n";
}

int partition(char *a,int low,int high,char pivot)
{
    int i = low;
    for(int j = low;j<high;j++){
        if(a[j]<pivot){
            swap(a[i],a[j]);
            i++;
        }else if(a[j] == pivot){
            swap(a[j],a[high]);
            j--;
        }
    }
    swap(a[i],a[high]);
    return i;
}

void matchPairs(char *nuts,char *bolts,int l,int h)
{
    if(l >= h)
        return;
    
    int pivot = partition(nuts,l,h,bolts[h]);
    partition(bolts,l,h,nuts[pivot]);

    matchPairs(nuts,bolts,l,pivot-1);
    matchPairs(nuts,bolts,pivot+1,h);
}


int main()
{
    char nuts[] = {'@', '#', '$', '%', '^', '&'};
    char bolts[] = {'$', '%', '&', '^', '@', '#'};

    // Method based on quick sort which 
    // matches nuts and bolts
    matchPairs(nuts, bolts, 0, 5);

    cout <<"Matched nuts and bolts are : \n";
    
    printArray(nuts);
    printArray(bolts);
    return 0;
}