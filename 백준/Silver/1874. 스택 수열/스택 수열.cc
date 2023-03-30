#include <iostream>
#include <string>
#include <stack>

int arr[200001];
int index = 0;

using namespace std;

int main(void)
{
	int n;
	int max = 0;
	stack<int> stack;
	bool fail = false;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if (stack.empty() || stack.top() < input)
		{
			for (int j = max + 1; j <= input; ++j)
			{
				stack.push(j);
				arr[index++] = 1;
			}
		}

		if (stack.top() == input)
		{
			if (!stack.empty())
			{
				stack.pop();
				arr[index++] = -1;
			}
		}
		else
		{
			fail = true;
		}

		if (input > max) max = input;
	}

	if (fail)
	{
		printf("NO");
	}
	else
	{
		for (int k = 0; k < index; ++k)
		{
			if (arr[k] == 1) printf("+\n");
			else if (arr[k] == -1) printf("-\n");
		}
	}


	return 0;
}