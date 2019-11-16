#include "BraceChecker.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool BraceChecker::isBalanced(const std::string& brace) {
    std:: stack <char> sequence;
    static bool  foo = true;
    try { if ((brace[0] == '}')||(brace[0] == ']')||(brace[0] == ')')) throw 3;

        for (int i=0; i < brace.size(); i++){

            char N = brace[i];


            if ((N == '(') || (N == '{') || (N == '[')){
                sequence.push(N);
            }

if ((sequence.empty()) & ((N == '}')||(N == ']')||(N == ')')))
            throw 3;

            if  (N == ')'){
                if(sequence.top()== '(')
                    sequence.pop();
                else throw 2;

            }

            if  (N == '}'){
                if(sequence.top()== '{')
                    sequence.pop();
                else throw 2;
            }

            if  (N == ']'){
                 if(sequence.top()== '[')
                    sequence.pop();
                else throw 2;
            }

        }

    } catch (int a) {
        foo = false;
    }

    if ((sequence.empty()&(foo))) {
        foo = true;
    }
    else foo = false;

    return foo;
}

int main() {
	std::string sequence;

	std::getline(std::cin, sequence);

	if (BraceChecker::isBalanced(sequence)) {
		std::cout << "Balanced" << std::endl;
	} else {
		std::cout << "Not balanced" << std::endl;
	}

	return 0;
}

