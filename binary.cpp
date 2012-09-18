#include<stdio.h>
#define P(n) printf("%d",n)
#define nl printf("\n")
void print(bool A[],int n)
{
	for(int i=0;i<n;i++)
		P(A[i]);
	nl;
}
void binary(bool A[],int n,int i,int from)
{
	if(i>=n)
		return;
	if(from!=0)
	{
	A[i]=0;
	print(A,n);
	}
	binary(A,n,i+1,0);
	A[i]=1;
	print(A,n);
	binary(A,n,i+1,1);
	A[i]=0;
}
/*void binary(bool A[],int n)
{
	if(n<1)
		print(A,n);
	else
	{
		A[n-1]=0;
		binary(A,n-1);
		A[n-1]=1;
		binary(A,n-1);
	}
}*/
int main()
{
	int n;
	scanf("%d",&n);
	bool A[n];
	for(int i=0;i<n;i++)
		A[i]=0;
	binary(A,n,0,1);
	return 0;
}
