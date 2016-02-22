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

bool is_anagram_sort(string a, string b){ // using sorting (not effective, use hashing for effectiveness)
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   for(int i=0;i<a.size();i++){
      if(a[i]!=b[i])
         return false;
   }
   return true;
}

int main()
{
   string a,b;
   cin >>a;
   cin >>b;
   cout << is_anagram_sort(a,b)<<endl;
   cout << a <<endl;
   return 0;
}

