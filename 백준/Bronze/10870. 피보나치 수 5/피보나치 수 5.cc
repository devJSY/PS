#include <iostream>

using namespace std;

int Func(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Func(n - 1) + Func(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	cout << Func(n) << '\n';

	return 0;
}