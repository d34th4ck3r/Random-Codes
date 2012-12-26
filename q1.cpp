#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int compare(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}

/*int findMin(int A[],int n)
{
    qsort(A,n,sizeof(int),compare);
    cout<<"A : "<<"n = "<<n<<endl;
    for(int i=0;i<n;i++)
	    cout<<" "<<A[i];
    cout<<endl;
    if(n==2)
    {
	    cout<<"A[0]=" <<A[0]<<endl;
	    return A[0];
    }
    int B[n-1];
    for(int i=0;i+1<n;i++)
    {
	int diff=A[i+1]-A[i];
	if(diff<0)
	{
		diff=-1*diff;
	}
	B[i]=diff;
   }
    cout<<"B : "<<"n="<<n-1<<endl; 
    for(int i=0;i<n-1;i++)
	    cout<<" "<<B[i];
    cout<<endl;
   int val=findMin(B,n-1);
   return val;
}*/

int findMin(int A[],int n)
{
	qsort(A,n,sizeof(int),compare);
	int sum=
	for(int i=0;i<n;i++)
	{
		
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    qsort(A,n,sizeof(A[0]),compare);
    int ans=findMin(A,n);
    printf("----%d\n",ans);
    return 0;
}
