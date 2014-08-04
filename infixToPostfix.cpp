#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits>
#include<limits.h>
#include<set>
#include<stdio.h>
#include<string.h>
using namespace std;

int precedence(char a){
	switch(a){
		case '/':
			return 4;
		case '*':
			return 3;
		case '+':
			return 2;
		case '-':
			return 2;
		case NULL:
			return 0;
	}
	return 0;
}

string infixToPostfix(string infix){
	string postfix="";
	std::stack<char> myStack;
	for(int i=0;i<infix.length();i++){
		char val=(char)infix[i];
//		cout<<postfix<<endl;
		if(val<='9' && val>='0'){
			postfix+=val;
			continue;
		}
		if(myStack.empty()){
			myStack.push(val);
			continue;
		}
		if(!myStack.empty() && precedence(val)>precedence(myStack.top())){
			myStack.push(val);
			continue;
		}
		while(!myStack.empty() && precedence(val)<=precedence(myStack.top())){
			postfix+=myStack.top();
			myStack.pop();
		}
		myStack.push(val);
	}
	while(!myStack.empty()){
		postfix+=myStack.top();
		myStack.pop();
	}
	return postfix;
}

int main()
{
	string infix;
	cin>>infix;
	string postfix=infixToPostfix(infix);
	cout<<postfix<<endl;
	return 0;
}

