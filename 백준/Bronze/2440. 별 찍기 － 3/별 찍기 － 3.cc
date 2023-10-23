#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (size_t i = n; i > 0; i--)
	{
		for (size_t j = i; j > 0; j--)
		{
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}

