#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
   	stack<char> stack;

	for (char ch : s)
	{
		if (ch == '(')
		{
			stack.push('(');
		}
		else
		{
			if (stack.empty())
			{
				return false;
			}
			else
			{
				stack.pop();
			}
		}
	}

	if (stack.empty()) return true;
	else return false;
}