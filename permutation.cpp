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

void swap(char *a,char *b){
	*a=*a+*b-(*b=*a);
}

void printPermutation(string word,int start,int end){
	if(end-start==0){
		cout<<word<<endl;
		return;
	}
	for(int i=start;i<end;i++){
		swap(&word[start],&word[i]);
		printPermutation(word,start+1,end);
		swap(&word[start],&word[i]);
	}
}

int main()
{
	string word;
	cin>>word;
	printPermutation(word,0,word.length());
	return 0;
}

