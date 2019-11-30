#include <iostream>
#include <string>
#include <iterator>
#include <list>
#include "BraceChecker.h"
#define N 3
using namespace std;
bool BraceChecker:: isBalanced(const std::string& st){
     list<char> s;
     auto a=s.begin();
     for(int i=0;i<st.length();i++){
        if(st[st.length()-i-1]=='{'||st[st.length()-i-1]=='('||st[st.length()-i-1]=='['||st[st.length()-i-1]=='}'||st[st.length()-i-1]==')'||st[st.length()-i-1]==']')
            a=s.insert(a,st[st.length()-i-1]);
     }
     auto it=s.begin();
     if(*it=='}'||*it==']'||*it==')') return 0;
     auto itnext=it;
     ++itnext;
     while(itnext!=s.end())
    {
        if(*itnext=='('||*itnext=='{'||*itnext=='['){
            ++it;
            ++itnext;
        }
        if(*itnext==')'){
            if(*it!='(')
                return 0;
            else{
                itnext=s.erase(itnext);
                it=s.erase(it);
                it--;
            }
        }
        if(*itnext=='}'){
            if(*it!='{')
                return 0;
            else{
                itnext=s.erase(itnext);
                it=s.erase(it);
                it--;
            }
        }
        if(*itnext==']'){
            if(*it!='[')
                return 0;
            else{
                itnext=s.erase(itnext);
                it=s.erase(it);
                it--;
            }
        }
       // copy(s.begin(),s.end(),ostream_iterator<char>(cout," ")); cout << endl;
        }
        if(s.empty())
            return 1;
        else return 0;



 }

/* int main(){
     string s;
     cin >> s;
     bool a=BraceChecker::isBalanced(s);
    if (a==0)
        cout << "NO";
    else cout << "YES";
 return 0;
 }*/
