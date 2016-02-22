#include<iostream>
#include<stack>

using namespace std;
class Solution{
   stack<char> my_stack;
   public:
      bool isValid(string s){
         for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
               my_stack.push(s[i]);
            }
            else{
               switch (s[i]){
                  case ')':
                     if(!my_stack.empty() && my_stack.top()=='('){
                        my_stack.pop();
                     }else{
                        return 0;
                     }
                     break;
                  case '}':
                     if(!my_stack.empty() && my_stack.top()=='{'){
                        my_stack.pop();
                     }else{
                        return 0;
                     }
                     break;
                  case ']':
                     if(!my_stack.empty() && my_stack.top()=='['){
                        my_stack.pop();
                     }else{
                        return 0;
                     }
                     break;
               }
            }
         }
         if(!my_stack.empty())
            return 0;
         return 1;
      }
};

int main(){
   Solution validate;
   cout<<validate.isValid("(){}[]")<<endl;
   return 0;
}
