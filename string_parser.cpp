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

char** Split(char* str,int size, char delimiter){
	char** parsedString=(char **)calloc(1000,sizeof(char*));
	for(int i=0;i<1000;i++)
		parsedString[i]=(char*)calloc(1000,sizeof(char));
	int start=0,end=1,counter=0;
	while(start!=end && end <= size){
		if(str[start]==delimiter){
			start++;
			end++;
			continue;
		}
//		printf("TEST %d %d\n",start,end);
//		printf("%s %d %c",str,size,delimiter);
		while(str[end]!=delimiter && end < size)
			end++;
//		printf("end = %d\n",end);
		int iterator=0;
		while(end-start>0){
			parsedString[counter][iterator++]=str[start++];
//			start++;
//			iterator++;
		}
		counter++;
		end++;
	}
	return parsedString;
}

int main()
{
	char* c=(char *)calloc(1000,sizeof(char));
	scanf("%[^\n]",c);
	char** parsed=Split(c,strlen(c),' ');
	for(int i=0;parsed[i][0]!=0;i++)
		printf("%s\n",parsed[i]);
	return 0;
}
