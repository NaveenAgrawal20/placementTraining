#include <iostream>
#include <math.h>
using namespace std;
#define MOD 1000000007

void createMaxSegmentTree(int segmentTree[], int arr[], int low, int high, int position) {
    if (low == high) {
        segmentTree[position] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    createMaxSegmentTree(segmentTree, arr, low, mid, 2 * position + 1);
    createMaxSegmentTree(segmentTree, arr, mid + 1, high, 2 * position + 2);
    segmentTree[position] = max(segmentTree[2 * position + 1], segmentTree[2 * position + 2]);
}

int query(int segment[], int low, int high, int qlow, int qup, int positon) {
    if (qlow <= low && qup >= high) // total overlap
        return segment[positon];
    if (qlow > high || qup < low) // no overlap
        return INT_MIN;     // for MAX
    int mid = (low + high) / 2;
    int minLeft = query(segment,low,mid,qlow,qup,2*positon + 1);
    int minRight = query(segment,mid+1,high,qlow,qup,2*positon + 2);
    return max(minLeft,minRight);
}
void update(int seg[],int idx,int val,int low,int high,int pos){
    if(idx < low || idx > high)
        return;
    if(low == high){
        seg[pos] = val;
        return;
    }
    int mid = (low + high) / 2;
    update(seg,idx,val,low,mid,2*pos+1);
    update(seg,idx,val,mid+1,high,2*pos+2);
    seg[pos] = max(seg[2 * pos + 1], seg[2 * pos + 2]);
}

void createMinSeg(int seg[],int arr[],int low,int high,int pos){
    if(low == high){
        seg[pos] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    createMinSeg(seg,arr,low,mid,2*pos+1);
    createMinSeg(seg,arr,mid+1,high,2*pos+2);
    seg[pos] = min(seg[pos*2 + 1],seg[2*pos+2]);
}
int getMinQuery(int seg[],int low,int high,int qlow,int qup,int pos){
    if(qlow <= low && qup >= high)
        return seg[pos];
    if(qlow > high || qup < low)
        return INT_MAX;
    int mid = (low + high)/2;
    int min1 = getMinQuery(seg,low,mid,qlow,qup,pos*2+1);
    int min2 = getMinQuery(seg,mid+1,high,qlow,qup,pos*2+2);
    return min(min1,min2);
}

// sum
void createSumSeg(int  seg[],int arr[],int low,int high,int pos)
{
    if(low == high){
        seg[pos] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    createSumSeg(seg,arr,low,mid,2*pos+1);
    createSumSeg(seg,arr,mid+1,high,2*pos+2);
    seg[pos] = seg[pos*2+1] + seg[pos*2+2];
}
int sumQuery(int seg[],int low,int high,int qlow,int qup,int pos){
    if(qlow <= low && qup >= high)
        return seg[pos];
    if(qlow > high || qup < low)
        return 0;
    int mid = (low+high)/2;
    int leftSum = sumQuery(seg,low,mid,qlow,qup,pos*2+1);
    int rightSum = sumQuery(seg,mid+1,high,qlow,qup,pos*2+2);
    return (leftSum + rightSum) % MOD;
}
int gcd(int a,int b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
void createGCDSeg(int seg[],int arr[],int low,int high,int pos){
    if(low == high){
        seg[pos] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    createGCDSeg(seg,arr,low,mid,pos*2+1);
    createGCDSeg(seg,arr,mid+1,high,pos*2+2);
    seg[pos] = gcd(seg[2*pos+1],seg[2*pos+2]);
}
int gcdQuery(int seg[],int low,int high,int qlow,int qup,int pos){
    if(low >= qlow && high <= qup)
        return seg[pos];
    if(low > qup || qlow > high)
        return 0;
    int mid = (low+high)/2;
    int gLeft = gcdQuery(seg,low,mid,qlow,qup,pos*2+1);
    int gRight = gcdQuery(seg,mid+1,high,qlow,qup,pos*2+2);
    return gcd(gLeft,gRight);
}

int main() {
    // prepQ
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    int n;
    cin>>T;
    while(T--){
        cin>>n;
        int a[n+1];
        for(int i = 1;i<n+1;i++){
            cin>>a[i];
        }
        int x = (int)ceil(log(n)/log(2));
        int sn = 2*(int)pow(2,x) - 1;
        int seg1[sn],seg2[sn];
        createMaxSegmentTree(seg1,a,1,n,0);
        createMinSeg(seg2,a,1,n,0);
        int q,qlow,qup;
        cin>>q;
        while(q--)
        {
            cin>>qlow>>qup;
            int max = query(seg1,1,n,qlow,qup,0);
            int min = getMinQuery(seg2,1,n,qlow,qup,0);
            if(qup - qlow + 1 == max - min + 1)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
/*
1
5
1 2 3 4 5
3
1 2
2 3
3 4

1
5
1 2 2 4 5
3
1 2
2 3
3 4

1
5
1 2 5 4 3
3
1 2
2 3
3 4

1
8
3 9 8 10 7 4 6 5
1
6 8
*/
