#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;


	int Min = min(a, b);
	int Max = max(a, b);

	if (Min == Max)
		cout << 0 << '\n';
	else
		cout << (Max - Min) - 1 << '\n';

	for (size_t i = Min + 1; i < Max; i++)
	{
		cout << i << " ";
	}

	return 0;
}

