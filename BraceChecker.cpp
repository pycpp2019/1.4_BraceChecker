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
        return true;
    }
    else
   {
        return false;
    }
    }
    
