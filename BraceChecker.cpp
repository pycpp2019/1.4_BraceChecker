#include <iostream>
#include <string>
#include "BraceChecker.h"
#include  <stack>


bool BraceChecker::isBalanced(const std::string &sr){
	std::stack <int>st;
    for(std::string::const_iterator it = sr.begin(); it != sr.end(); ++it){
		if(*it == '('){
			st.push(1);
		}
		if(*it == '{'){
			st.push(2);
		}
		if(*it == '['){
			st.push(3);
		}
		if(*it == ')'){
			if(!st.empty()){
				if(st.top() == 1 ){
					st.pop();	
				}
				else{
					return 0;
				}
			}
			else{
					return 0;
				}
		}
		if(*it == '}'){
			if(!st.empty()){
				if(st.top() == 2 ){
					st.pop();	
				}
				else{
					return 0;
				}
			}
			else{
					return 0;
				}
		}
		if(*it == ']'){
			if(!st.empty()){
				if(st.top() == 3 ){
					st.pop();	
				}
				else{
					return 0;
				}
			}
			else{
					return 0;
				}
		}
	}
	if(st.size() == 0){
		return 1;
	}
	else{
		return 0;
	}
		
}

