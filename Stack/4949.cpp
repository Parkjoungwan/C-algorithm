#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
 for(;;){
   stack<char> st;
   string s;
   getline(cin,s);
   if(s=="."){
     break;
   }
   int check = 0;
   for (int i=0;i<s.size();i++){
     char c = s[i];
     if(c=='('||c=='['){
       st.push(c);
     }else if(c==')'){
       if(st.empty()||st.top()!='('){
         check = 1;
         break;
       }
       st.pop();
     }else if(c==']'){
       if(st.empty()||st.top()!='['){
         check = 1;
         break;
       }
       st.pop();
     }
   }
  if(check||!st.empty()) cout<<"no\n";
  else cout << "yes\n";
 }
}



