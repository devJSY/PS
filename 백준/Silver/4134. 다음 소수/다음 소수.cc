#include <iostream>
#include <math.h>

using namespace std;

bool IsprimeNum(long long n)
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

	int num = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		long long n = 0;
		cin >> n;

		if (n >= 0 && n <= 2)
			cout << 2 << endl;
		else if (n == 3)
			cout << 3 << endl;
		else 
		{
			while (!IsprimeNum(n))
				n++;


			cout << n << '\n';
		}
	}

	return 0;
}