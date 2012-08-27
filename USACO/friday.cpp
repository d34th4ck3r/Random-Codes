/*
ID: gautam11
PROG: friday
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#define nl printf("\n")
using namespace std;
int numberOfDays(int month,int year)
{
	if(month==1)		//jan
		return 31;
	if(month==2)
	{		
		if(year%4!=0 && year%100!=0)
			return 28;
		else if(year%4==0 && year%100!=0)
		{
//			cout<<"--------------LEAP YEAR"<<endl;
			return 29;
		}
		else if(year%100==0 && year%400!=0)
		{
			return 28;
		}
		else if(year%400==0)
		{
//			cout<<"--------------LEAP YEAR"<<endl;
			return 29;
		}
	}
	if(month==3)		//mar
		return 31;
	if(month==4)		//apr
		return 30;
	if(month==5)		//may
		return 31;
	if(month==6)		//jun
		return 30;
	if(month==7)		//jul
		return 31;
	if(month==8)		//aug
		return 31;
	if(month==9)		//sep
		return 30;
	if(month==10)		//oct
		return 31;
	if(month==11)		//nov
		return 30;
	if(month==12)		//dec
		return 31;
}
string name(int month)
{
	switch(month)
	{
		case 1:return "JAN";
		case 2:return "FEB";
		case 3:return "MAR";
		case 4:return "APR";
		case 5:return "MAY";
		case 6:return "JUN";
		case 7:return "JUL";
		case 8:return "AUG";
		case 9:return "SEP";
		case 10:return "OCT";
		case 11:return "NOV";
		case 12:return "DEC";
	}
}
int main()
{
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int N;
	fin>>N;
	int days[7]={0};
	int start=13%7;
	int day=start;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=12;j++)
		{
			if(i==1 && j==1)
				day=start;
			else if(j==1)
			{
//				cout<<"number of days "<< 12 <<" month are : "<< numberOfDays(12,1990+(i-1)-1) <<endl;
				day=(day+numberOfDays(12,1900+(i-1)-1))%7;
//				cout<<"So, Day on "<< name(1)<<" month of "<<1900+(i-1)<<" year is "<< day<<endl;
			}
			else
			{
//				cout<<"number of days in "<<j-1<<" month are : "<< numberOfDays(j-1,1990+(i-1)) <<endl;
				day=(day+numberOfDays(j-1,1900+(i-1)))%7;
//				cout<<"So, Day on "<<name(j)<<" month of "<<1900+(i-1)<<" year is "<< day<<endl;
			}
			days[day]++;
		}
	}
	fout<<days[6]<<" ";
	for(int i=0;i<6;i++)
	{
		fout<<days[i];
		if(i!=5)
			fout<<" ";
	}
	fout<<endl;
	return 0;
}
