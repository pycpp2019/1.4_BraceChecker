#include "BraceChecker.h"
#include <iostream>
using namespace std;


bool BraceChecker::isBalanced(const std::string& str)
{   
    string S=str;
    string S2="";
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
    n=S.length();
    for (int i=0; i<n; i++)
    {
    
        if (S[i] == '(' || S[i] == '{' || S[i] == '[')
        {
           S2=S2+S[i];

        }
         /*
            int pos;
            pos=S.find(']');
            if (pos==-1) break;
          //  if (S[pos-1]=='(' || S[pos-1]=='{') break;
            S.erase(pos,1);
            S.erase(0,1);*/
        
        if (S[i] == ')')
        {
            S2=S2+')';
            if (S2[S2.length()-2]=='(')
            {
                S2.erase(S2.length()-2,2);
            }
            else break;
        }
        else
        {
            
            if (S[i] == '}')
            {
                S2=S2+'}';
                if (S2[S2.length()-2]=='{')
                {
                    S2.erase(S2.length()-2,2);
                }
                else break;
            }
            else 
            {
                 if (S[i] == ']')
                {
                    S2=S2+"]";
                    if (S2[S2.length()-2]=='[')
                    {
                        S2.erase(S2.length()-2,2);
                    }
                     else break;
                }
            }
    
        }
        
    }
    
    if (S2.length()==0)
    {
        //cout<<"Balanced"<<endl;
        return true;
    }
    else
    {
      //  cout<<"Not balanced"<<endl;
        return false;
    }
    }
    
 
    

