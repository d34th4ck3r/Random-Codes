#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits>
#include<limits.h>
#include<set>
#include<stdio.h>
#include<string.h>
using namespace std;

void fillNotPrime(int *not_prime,int size){
	int filler=2;
	while(filler<(size+1)){
		if(not_prime[filler]==1){
			filler++;
			continue;
		}
		int i=1;
		while(filler*i<(size+1)){
			not_prime[filler*i]=1;
			i++;
		}
	}
}

int GCD(int a,int b)
{
	if(a==0) return b;
	return GCD(b%a,a);
}
int main()
{
	int T;
	scanf("%d",&T);
//	bool *not_prime=(bool *)calloc(100001,sizeof(bool));
//	fillNotPrime(not_prime,100000)
	while(T--){
		int N;
		scanf("%d",&N);
		int A[N];
		for(int i=0;i<N;i++)
			scanf("%d",&A[i]);
		int flag=0;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if(GCD(A[i],A[j])==1){
					printf("YES\n");
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

