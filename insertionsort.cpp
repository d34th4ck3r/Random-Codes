#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits>
#include<set>
#include<stdio.h>
#include<string.h>
using namespace std;

void swap(int* a,int *b){
	*a=*a+*b-(*b=*a);
}

void insertionsort(int* values,int size)
{
	int pointer=1;
	while(pointer<size){
		int i=pointer-1;
		for(;i>=0;i--)
			if(values[i]<values[pointer])
				break;
		for(int j=pointer;j>i+1;j--)
			swap(&values[j],&values[j-1]);
		pointer++;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	int* values=(int*)calloc(N,sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d",&values[i]);
	insertionsort(values,N);
	for(int i=0;i<N;i++)
		printf("%d ",values[i]);
	printf("\n");
	return 0;
}
