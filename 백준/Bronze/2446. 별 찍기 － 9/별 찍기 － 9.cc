#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (size_t j = 0; j < (2 * (n - i)) - 1; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}

	for (size_t i = 2; i < n + 1; i++)
	{
		for (size_t j = 0; j < n - i; j++)
		{
			cout << " ";
		}
		
		for (size_t j = 0; j < (2 * i) - 1; j++)
		{
			cout << "*";
		}

		cout << '\n';
	}

	return 0;
}

