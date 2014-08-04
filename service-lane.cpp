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

int find_min(int start,int end,int array[])
{
	int min=INT_MAX;
	for(int i=start;i<=end;i++)
		if(min>array[i])
			min=array[i];
	return min;
}

int main()
{
	int N,T;
	scanf("%d %d",&N,&T);
	int width[N];
	for(int i=0;i<N;i++)
		scanf("%d",&width[i]);
	while(T--){
		int start,end;
		scanf("%d %d",&start,&end);
		printf("%d\n",find_min(start,end,width));
	}
	return 0;
}

