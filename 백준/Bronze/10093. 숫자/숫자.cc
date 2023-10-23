#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;


	long long Min = min(a, b);
	long long Max = max(a, b);

	if (Min == Max)
		cout << 0 << '\n';
	else
		cout << (Max - Min) - 1 << '\n';

	for (long long i = Min + 1; i < Max; i++)
	{
		cout << i << " ";
	}

	return 0;
}

