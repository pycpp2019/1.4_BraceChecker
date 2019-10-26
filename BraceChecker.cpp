#include "BraceChecker.h"
#include <iostream>
#include <string>
#include <stack>




inline static bool processing(const char symb, std::stack<char>& str_stack) {
	if(!str_stack.empty() && str_stack.top() == symb) {
		str_stack.pop();
		return true;
	} else {
		std::cout << "Not balanced" << std::endl;
		return false;
	}
}


bool BraceChecker::isBalanced(const std::string& str) {
	std::stack<char> str_stack;
	auto iter_str = str.begin();

	while(iter_str != str.end()) {
		switch (*iter_str) {
		case '(':
			str_stack.push('(');
			break;
		case '{':
			str_stack.push('{');
			break;
		case '[':
			str_stack.push('[');
			break;
		case ')':
			if(!processing('(', str_stack)) {
				return false;
			}
			break;
		case '}':
			if(!processing('{', str_stack)) {
				return false;
			}
			break;
		case ']':
			if(!processing('[', str_stack)) {
				return false;
			}
			break;
		}

		iter_str++;
	}

	if(str_stack.empty()) {
		std::cout << "Balanced" << std::endl;
		return true;
	} else {
		std::cout << "Not balanced" << std::endl;
		return false;
	}
}