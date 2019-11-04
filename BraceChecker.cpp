#include "BraceChecker.h"

bool BraceChecker::isBalanced(const std::string& input)
{
	try{return !(std::accumulate(input.begin(), input.end(), double(1), [] (double x, char y)
		{
			if (x < 1) { throw 1;}
			if (y == '{') { return x*2; }
			if (y == '}') { return x/2; }
			if (y == '[') { return x*3; }
			if (y == ']') { return x/3; }
			if (y == '(') { return x*5; }
			if (y == ')') { return x/5; }
			else { return x; }
		}) - 1);}
	catch (int msg)
	{
		return 0;
	}
}