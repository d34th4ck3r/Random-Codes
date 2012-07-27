/*
ID: gautam11
PROG: ride
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;
int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet,group;
	fin>>comet;
	fin>>group;
	long sc=1,sg=1;
	for(int i=0;i<comet.size();i++)
	{
		sc=sc*(comet[i]-'A'+1);
	}
	for(int i=0;i<group.size();i++)
	{
		sg=sg*(group[i]-'A'+1);
	}
	if(sc%47==sg%47)
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;
	return 0;
}
