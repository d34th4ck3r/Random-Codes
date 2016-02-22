#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits>
#include<set>

using namespace std;

struct Node{
   int val;
   Node *next;
   Node(int x): val(x), next(NULL){}
};

bool check_substring(string sub,string main){
   int c_sub=0,c_main=0;
   while(c_sub<sub.length() && c_main<main.length()){
      while(sub[c_sub]!=main[c_main]){
         c_main++;
         if(c_main>=main.length())
            return 0;
      }
      while(sub[c_sub]==main[c_main]){
         c_sub++;
         c_main++;
         if(c_sub>=sub.length())
            return 1;
         if(c_main>=main.length())
            return 0;
      }
      c_sub=0;
   }
}

int main()
{
   string sub,main;
   cin>>main;
   cin>>sub;
   cout<<check_substring(sub,main)<<endl;
   return 0;
}
