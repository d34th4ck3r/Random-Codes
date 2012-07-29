/*
ID: gautam11
PROB: gift1
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<tr1/unordered_map>
#include<fstream>
#define nl printf("\n")
using namespace std;
using namespace std::tr1;
int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	unordered_map<string,int> money;
	int NP;
	fin>>NP;
	string names[NP];
	for(int i=0;i<NP;i++)
	{
		fin>>names[i];
		money[names[i]]=0;
	}
	for(int i=0;i<NP;i++)
	{
		string giver;
		fin>>giver;
//		cout<<"giver set to : " <<giver <<endl;
		int amount=0;
		fin>>amount;
		money[giver]=money[giver]-amount;
//		cout<<"So, now the money of "<<giver<<" is "<< money[giver]<<endl;
		int number=0;
		fin>>number;
		string taker;
		for(int j=0;j<number;j++)
		{
			fin>>taker;
//			cout<<"amount : " <<amount<<" "<<"number : "<<number<<endl;
			if(number!=0)
			{
				money[taker]=money[taker]+(int)amount/number;
//				cout<<giver<<" gives "<<(int)amount/number<<" money to "<<taker<<" so now "<<taker<<" has "<<money[taker]<<" money"<<endl;
			}
		}
		if(number!=0)
		{
			money[giver]=money[giver]+(amount-(((int)amount/number)*number));
//			cout<<"Final money with "<<giver<<" : "<<money[giver]<<endl;
		}
	}
	for(int i=0;i<NP;i++)
	{
		fout<<names[i]<<" "<<money[names[i]]<<endl;
	}
	return 0;
}
