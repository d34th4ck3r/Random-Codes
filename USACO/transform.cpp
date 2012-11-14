/*
ID: gautam11
PROG: transform
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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

bool Compare(char **Tiles,char **modTiles,int N)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(Tiles[i][j]!=modTiles[i][j])
				return 0;
	return 1;
}

char** RotateBy90(char **Tiles,int N)
{
	char **modTiles;
	modTiles=(char **)malloc(sizeof(char *)*N);
	for(int i=0;i<N;i++)
		modTiles[i]=(char *)malloc(sizeof(char)*N);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			modTiles[i][j]=Tiles[N-1-j][i];

	return modTiles;
}
char** Reflection(char **Tiles,int N)
{
	char **modTiles;
	modTiles=(char **)malloc(sizeof(char *)*N);
	for(int i=0;i<N;i++)
		modTiles[i]=(char *)malloc(sizeof(char)*N);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			modTiles[i][j]=Tiles[i][N-1-j];

	return modTiles;
}
int main()
{
	freopen ("transform.in", "r", stdin);
	freopen ("transform.out", "w", stdout);
	int N;
	Sint(N);
	char **Tiles;
	Tiles=(char **)malloc(sizeof(char *)*N);
	for(int i=0;i<N;i++)
		Tiles[i]=(char *)malloc(sizeof(char)*N);
	char **finalTiles;
	finalTiles=(char **)malloc(sizeof(char *)*N);
	for(int i=0;i<N;i++)
		finalTiles[i]=(char *)malloc(sizeof(char)*N);
	for(int i=0;i<N;i++)
		scanf("%s",Tiles[i]);
	for(int i=0;i<N;i++)
		scanf("%s",finalTiles[i]);
	char **modTiles;
	modTiles=RotateBy90(Tiles,N);
	if(Compare(modTiles,finalTiles,N))
	{
		printf("1\n");
		return 0;
	}
	modTiles=RotateBy90(modTiles,N);
	if(Compare(modTiles,finalTiles,N))
	{
		printf("2\n");
		return 0;
	}
	modTiles=RotateBy90(modTiles,N);
	if(Compare(modTiles,finalTiles,N))
	{
		printf("3\n");
		return 0;
	}
	modTiles=Reflection(Tiles,N);
	if(Compare(modTiles,finalTiles,N))
	{
		printf("4\n");
		return 0;
	}
	for(int i=0;i<3;i++)
	{
		modTiles=RotateBy90(modTiles,N);
		if(Compare(modTiles,finalTiles,N))
		{
			printf("5\n");
			return 0;
		}
	}
	if(Compare(Tiles,finalTiles,N))
	{
		printf("6\n");
		return 0;
	}
	printf("7\n");	
	return 0;
}
