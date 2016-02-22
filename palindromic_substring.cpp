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

bool palindrome(string s){
	int start=0,end=s.size()-1;
	while(s[start]==s[end] && start<=end){
		start++;
		end--;
	}
	if(start>end)
		return true;
	return false;
}


int palindromic_substring(string s){
	map<string,int> pal;
	int pointer=0;
	while(pointer<s.size()){
		string c(1,s[pointer]);
		if(pal.find(c) == pal.end())
			pal[c] = 1;
		else
			pal[c] += 1;
		int start = pointer-1,end = pointer+1;
		while(start>=0 && end < s.size() && s[start]==s[end]){
			string substr = s.substr(start,end-start+1);
			if(pal.find(substr) == pal.end())
				pal[substr] = 1;
			else
				pal[substr] += 1;
			start--;
			end++;
		}
		start = pointer;
		end = pointer+1;
		while(start>=0 && end < s.size() && s[start]==s[end]){
			string substr = s.substr(start,end-start+1);
			if(pal.find(substr) == pal.end())
				pal[substr] = 1;
			else
				pal[substr] += 1;
			start--;
			end++;
		}
		pointer++;
	}
	return pal.size();
}


int main()
{
	string s;
	cin>>s;
	cout << palindromic_substring(s) << endl;
	return 0;
}

