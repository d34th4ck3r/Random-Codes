/*
ID: gautam11
PROG: beads
LANG: C++
*/

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
char notindex(char var)
{
	if(var=='b')
		return 'r';
	else if(var=='r')
		return 'b';
	else
		return 'w';
}
using namespace std;
int count(int index,string necklace){
	int pointer=index;
	int count=0;
	int N=necklace.size();
	int visited[N];
	for(int i=0;i<N;i++)
		visited[i]=0;
	if(index+1<N && necklace[index]==necklace[index+1])
		return 0;
//	cout<<"For index "<< index<<" Left side : " <<endl;
	int val;
	while(necklace[pointer]=='w' && visited[pointer]==0)
	{
		visited[pointer]=-1;
		count++;
		pointer--;
		if(pointer<0)
			pointer=N+pointer;
		if(pointer==index)
			break;
	}
	val=pointer;
	while(necklace[pointer]!=notindex(necklace[val]) && visited[pointer]==0)
	{
		visited[pointer]=-1;
//		cout<<necklace[pointer];
		count++;
		pointer--;
		if(pointer<0)
			pointer=N+pointer;
		if(pointer==index)
			break;
	}
//	cout<<endl;
	pointer=index+1;
	if(pointer>=N)
		pointer=pointer-N;
//	cout<<"For index "<< index<<" Right side : " <<endl;
	while(necklace[pointer]=='w' && visited[pointer]==0)
	{
		visited[pointer]=1;
		count++;
		pointer++;
		if(pointer>=N)
			pointer=pointer-N;
		if(pointer==index)
			break;
	}
	val=pointer;
	while(necklace[pointer]!=notindex(necklace[val]) && visited[pointer]==0)
	{
		visited[pointer]=1;
//		cout<<necklace[pointer];
		count++;
		pointer++;
		if(pointer>=N)
			pointer=pointer-N;
		if(pointer==index)
			break;
	}
//	cout<<endl;
//	cout<<endl<<"Count for index "<<index << " is : "<<count<<endl;
	return count;
}
int main()
{
	int N;
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	fin >>N;
	string necklace;
	fin >> necklace;
//	cout<<necklace_chain<<endl;
//	string necklace_ring=necklace_chain.append(necklace_chain);
	int max=0;
	int max_allowed_index=N;
	int index=0;
	for(int i=0;i<N;i++)
	{
		while(i==0 && necklace[i]=='w')
			i++;
		int val=count(i,necklace);
//		cout<<"Checking if max("<<max<<") is smaller then val("<<val<<")"<<endl;
		if(max<val)
		{
			max=val;
			index=i;
		}
//		cout<<"max till index "<<index <<" is : "<<max<<endl;
	}
//	cout<<max<<" at index : " << index+1<<endl;
	fout<<max<<endl;
	return 0;
}
