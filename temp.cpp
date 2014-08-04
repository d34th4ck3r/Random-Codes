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

int main()
{
	int a[3];
	a[0]=3;
	a[1]=2;
	a[2]=1;
	sort(a,a+3);
	printf("%d %d %d",a[0],a[1],a[2]);
	return 0;
}

