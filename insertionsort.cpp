#include<stdio.h>
using namespace std;
#define nl printf("\n")
void insertionsort(int values[])
{
	for(int i=0;i<values.size;i++)
	{
		printf("%d ",values[i]);
	}
}

int main(){
	int n=0;	
	scanf("%d",&n);
	int values[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&values[i]);
	}
	insertionsort(values);
	return 0;
}
