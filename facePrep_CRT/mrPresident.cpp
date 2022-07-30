//YOUR CODE// 
 
#include <iostream>
using namespace std;

int main() 
{
   // Try out your code here
    cout << "Hello, World!";
    return 0;
}
 
 //YOUR CODE ENDS// 
 
 
 //SOLUTION MENTIONED BELOW // 
 
 
#include<stdio.h>
#define MOD 1000000007
#define get getchar_unlocked
class subset
{
	public:
	int v;
	int parent;
	int rank;
	subset()
	{
			}
	subset(int v)
	{
		this->v=v;
		parent=v;
		rank=0;
	}
};
 
int getInt()
{
	int N=0;
	char c=get();
	while(c<'0'||c>'9')
	c=get();
	while(c<='9'&&c>='0')
	{
	    N=(N<<3)+(N<<1)+c-'0';
	    c=get();
	}
//	scanf("%d",&N);
	return N;
}
 
class connection
{
public:
	int M;
	int *A;
	int *B;
	 int *C;
	
	connection(int M)
	{
		this->M=M;
		A=new int[M];
		B=new int[M];
		C=new int[M];
		
		int i;
		for(i=0;i<M;i++)
		{
			int a=getInt()-1;
			int b=getInt()-1;
			int c=getInt();
			
			A[i]=a;
			B[i]=b;
			C[i]=c;
		}
	}
	void swap(int a,int b)
	{
		int temp=C[a];
		C[a]=C[b];
		C[b]=temp;
		
		temp=A[a];
		A[a]=A[b];
		A[b]=temp;
		
		temp=B[a];
		B[a]=B[b];
		B[b]=temp;
	}  
 
 
 
	int partition(int a,int b)
	{
		int key=C[(a+b)/2];
		int left=a;
		int right=b;
		
		while(left<right)
		{
			while(C[left]<key)
			left++;
			
			while(C[right]>key)
			right--;
			
			if(left!=right&&C[left]==C[right])
			{
				left++;
				right--;
			}
			
			if(left<right)
			swap(left,right);
		}
		return right;
	}
	void QuickSort(int a,int b)
	{
		if(a<b)
		{
			int pivot=partition(a,b);
			QuickSort(a,pivot);
			QuickSort(pivot+1,b);
		}
	}
	void sort()
	{
		QuickSort(0,M-1);
	}
	
};
class node
{
    public:
    int v;
    node *next;
    node(int v)
    {
        this->v=v;
    }
};
class Stack
{
    public:
    node *top;
    int size;
    Stack()
    {
        size=0;
        top=NULL;
    }
    void push(int v)
    {
        size++;
        node *temp=new node(v);
        temp->next=top;
        top=temp;
    }
};
	
class MST
{
	public:
		//list* adlist;
		int N,M;
		long long minWeight;
		subset* sub;
		Stack edges;
		connection *con;
		MST(int N,int M)
		{
			this->N=N;
			minWeight=0;
			this->M=M;
		//	adlist=new list[N];
			sub=new subset[N];
			int i;
			for(i=0;i<N;i++)
			sub[i]=subset(i);
			con=new connection(M);
			con->sort();
		}
		int giveParent(int child)
		{
			while(sub[child].parent!=child)
				child=sub[child].parent;
				
				return child;
		}
		void setRank(int root1,int root2)
		{
			if(sub[root1].rank>sub[root2].rank)
			sub[root2].parent=sub[root1].parent;
			else
			if(sub[root2].rank>sub[root1].rank)
			sub[root1].parent=sub[root2].parent;
			else
			{
			sub[root1].parent=sub[root2].parent;
			sub[root1].rank++;
			sub[root2].rank++;
			}
		}
		void join(int a,int b)
		{
			int root1=giveParent(a);
			int root2=giveParent(b);
			
			setRank(root1,root2);
		}
		int  isCycle(int a,int b)
		{
			int root1,root2;
			root1=giveParent(a);
			root2=giveParent(b);
			
			if(root1==root2)
			return 1;
			else
			return 0;
		}
		void makeMST()
		{
			int i,check;
			for(i=0;i<M;i++)
			{
				check=isCycle(con->A[i],con->B[i]);
				if(check==0)
				{
			    edges.push(i);
				join(con->A[i],con->B[i]);
				minWeight=(minWeight+con->C[i]);
				}
			}
		}
		long long int find(long long int K)
		{
		    if(edges.size>K||edges.size!=(N-1))
		    return -1;
		    
		    node *temp=edges.top;
		    long long int count=0;
		    while(minWeight>K&&temp)
		    {
		        minWeight-=con->C[temp->v];
		        minWeight++;
		        temp=temp->next;
		        count++;
		    }
		    return count;
		}
};
 
 
int main()
{
	int T=1;
	//getInt();
	while(T--)
	{
		int N=getInt();
		int M=getInt();
		long long int K;
		scanf("%lld",&K);
		MST *mst=new MST(N,M);
		mst->makeMST();
		printf("%lld\n",mst->find(K));
	}
}
 
 //SOLUTION ENDS//