#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int num = n;

	for (int i = 2; i <= num; i++)
	{
		while (n % i == 0)
		{
			cout << i << endl;
			n = n / i;
			if (n <= 1) return 0;
		}
	}

    return 0;
}
