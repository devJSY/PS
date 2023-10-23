#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int y = 0;
	int m = 0;

	for (size_t i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		y += ((num / 30) + 1) * 10;
		m += ((num / 60) + 1) * 15;
	}

	if (y == m)
	{
		cout << "Y M " << y;
	}
	else if (y < m)
	{
		cout << "Y " << y;
	}
	else if (m < y)
	{
		cout << "M " << m;
	}

	return 0;
}

