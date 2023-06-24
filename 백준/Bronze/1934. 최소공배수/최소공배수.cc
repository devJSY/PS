#include <iostream>

using namespace std;

int Maxnum(int a, int b)
{
	int Min = min(a, b);
	int result = 1;

	for (size_t i = 1; i <= Min; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			result = i;
		}
	}


	return result;
}

int main()
{
	int t = 0;
	cin >> t;

	int a = 0;
	int b = 0;

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;

		int factor = Maxnum(a, b);

		cout << a * b / factor << '\n';
	}

	return 0;
}