/*
ID: gautam11
PROG: calfflac
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<ctype.h>
#include<limits.h>
#include<set>
#include<stack>
#include<queue>
#define P(s) printf("%s\n",s)
#define Pint(n) printf("%d",n)
#define Sint(n) scanf("%d",&n)
#define TEST printf("Test Called!")
#define NL printf("\n")
typedef struct node{
	int value;
	struct node *next;
}node;
 
typedef struct BinaryTree{
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BinaryTree;
 
using namespace std;
int compare(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}
void getLongestContinousPalindrome(char* ori_str,int ori_len,char* str,int len,int* mapper,int *ans,int table[])
{
	int start=-1,maxLen=1;
	for(int i=0;i<len;i++)
	{
			table[i]=i;
	}
	for(int i=0;i<len-1;i++)
	{
		if(str[i]==str[i+1])
		{
			start=i;
			maxLen=2;
			table[i]=i+1;
		}
	}
	for(int l=3;l<=2000;l++)
	{
		for(int i=0;i<len-l+1;i++){
			int j=i+l-1;
			if( table[i+1]==j-1 && str[i]==str[j]){
				table[i]=j;
				if(l>maxLen)
				{
					start=i;
					maxLen=l;
				}
			}
		}
	}
	ans[0]=maxLen;
	ans[1]=start;
}

int main()
{
	freopen ("calfflac.out", "w", stdout);
	FILE *file=fopen("calfflac.in","r");
	char* s=(char *)calloc(20000,sizeof(char));
	size_t n = 0;
	int c;

	if (file == NULL)
		return 0; 

	while ((c = fgetc(file)) != EOF)
	{
		s[n++] = (char) c;
	}
	s[n] = '\0';        
	int len=n;
	char *final_s=(char *)calloc(20000,sizeof(char));
	int *mapper=(int *)calloc(20000,sizeof(int));
	int final_len=0;
	for(int i=0;i<len;i++)
	{
		if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') )
		{
			final_s[final_len]=tolower(s[i]);
			mapper[final_len]=i;
			final_len++;
		}
	}
	int *ans=(int*)calloc(2,sizeof(int));
	int maxLen=-1,start=-1;
	int table[20000]={0};
	getLongestContinousPalindrome(s,len,final_s,final_len,mapper,ans,table);
	maxLen=ans[0];
	start=ans[1];
	printf("%d\n",maxLen);
	for(int i=mapper[start];i<=mapper[start+maxLen-1];i++)
		printf("%c",s[i]);
	NL;
	return 0;
}
