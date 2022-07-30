#include <bits/stdc++.h>
using namespace std;
int parent(int i)
{
     return (i-1)/2;
}
int left(int i)
{
     return (i*2)+1;
}
int right(int i)
{
     return (i*2)+2;
}
void swap(char *a,char *b)
{
     char temp = *a;
     *a = *b;
     *b = temp;
}
void insert(char heap[],int *size, int val)
{
     heap[*size]= val;
     int i = *size;
     (*size)++;
     while(i!=0 && heap[parent(i)]>heap[i])
     {
     swap(&heap[parent(i)],&heap[i]);
     i = parent(i);
     }
}
void heapify(char heap[],int i,int size)
{
     int l = left(i);
     int r = right(i);
     int s = i;
     if(l<size && heap[l]<heap[i])
        s = l;
     if(r<size && heap[r]<heap[s])
        s = r;
     if(s!=i)
     {
     swap(&heap[i],&heap[s]);
     heapify(heap,s,size);
     }
}
char extract(char heap[],int *size)
{
     char root = heap[0];
     heap[0] = heap[*size-1];
     (*size)--;
     heapify(heap,0,*size);
     return root;
}
int main()
{
    int t;
    cin>>t;
  while(t--)
  {
    string s;
    int q, size=0;
    cin>>s;
    cin>>q;
    int n = s.length();
    char *heap = (char *)malloc(sizeof(char)*n);
    int i = 0;
    for(int j=0;j<q;j++)
    {
        insert(heap,&size,s[j]);
        i = j+1;
        if(i==n)
         break;
    }
    while(i<n)
    {
        cout<<extract(heap,&size);
        insert(heap,&size,s[i]);
        i++;
    }
    while(size)
    {
         cout<<extract(heap,&size);
    }
    cout<<endl;
  }
 return 0;
}