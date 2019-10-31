#include "BraceChecker.h"
#include <iostream>
using namespace std;


bool BraceChecker::isBalanced(const std::string& str)
{   
    string S=str;
     int n=S.length();
    for (int i=0; i<n; i++)
    {
        if (S[i] != '{' && S[i] != '}'&&S[i] != '[' && S[i] != ']' && S[i] != '(' && S[i] != ')')
        {
        S.erase(i,1);
        i=i-1;
        n=n-1;
        }
    }
    while(S.length()!=0)
    {
        if ( S[0] == '}'|| S[0] == ']'|| S[0] == ')')
        break;
        if (S[0] == '(')
        {
            int pos;
            pos=S.find(')');
            if (pos==-1) break;
         //   if (S[pos-1]=='{' || S[pos-1]=='[') break;
            S.erase(pos,1);
            S.erase(0,1);
        }
        else{
        if (S[0] == '{')
        {
            int pos;
            pos=S.find('}');
            if (pos==-1) break;
          //  if (S[pos-1]=='(' || S[pos-1]=='[') break;
            S.erase(pos,1);
            S.erase(0,1);
        }
        else{
        if (S[0] == '[')
        {
            int pos;
            pos=S.find(']');
            if (pos==-1) break;
          //  if (S[pos-1]=='(' || S[pos-1]=='{') break;
            S.erase(pos,1);
            S.erase(0,1);
        }}}
    }
    
    if (S.length()==0)
    {
        cout<<"Balanced"<<endl;
        return true;
    }
    else
    {
        cout<<"Not balanced"<<endl;
        return false;
    }
    
}
