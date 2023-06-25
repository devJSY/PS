#include <iostream>
#include <math.h>

using namespace std;

bool IsPrimeNum(int n)
{
	for (size_t i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int m = 0;

	cin >> n >> m;

	for (size_t i = n; i <= m; i++)
	{
		if (i >= 0 && i <= 1) continue;
		else
		{
			if (IsPrimeNum(i)) cout << i << '\n';
		}			
	}

	return 0;
}