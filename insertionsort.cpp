#include<stdio.h>
using namespace std;
#define nl printf("\n")
void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}
void insertionsort(int values[], int n)
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		k=i;
		int j=i-1;
		while(j>=0)
		{
			if(values[k]<values[j])
			{
				swap(values[j],values[k]);
				k=j;
			}
			j--;
		}
	}
/*	for(int i=0;i<n;i++)
	{
		printf("p%d ",values[i]);
	}*/
}

int main(){
	int n=0;	
	scanf("%d",&n);
	int values[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&values[i]);
	}
	insertionsort(values,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",values[i]);
	}
	nl;
	return 0;
}
