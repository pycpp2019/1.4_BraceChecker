#include "BraceChecker.h"

bool BraceChecker::isBalanced(const std::string& a)
{
	std::string input = a;
	for (int i = 0; i < input.size(); ++i)
	{
		if ((input[i] != '{') && (input[i] != '}') && (input[i] != '(') && (input[i] != ')') && (input[i] != '[') && (input[i] != ']'))
		{
		    input.erase(i,1);
		    i--;
		}
	}
	input = "bgn" + input;
	int k;
	while (1==1)
	{
		k = 0;
		for (int i = 0; i < input.size() - 1; ++i)
		{
			if ((input[i] == '{') && (input[i+1] == '}')) { input.erase(i,2); i -= 1; k++; }
			if ((input[i] == '(') && (input[i+1] == ')')) { input.erase(i,2); i -= 1; k++; }
			if ((input[i] == '[') && (input[i+1] == ']')) { input.erase(i,2); i -= 1; k++; }
		}
		if (k == 0) { break; }
	}
	if (input.size() == 3) { return 1; } else { return 0; }
}