#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;

	int a = 0;
	int b = 0;
	int c = 0;

	int arr[101] = {};

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		for (int j = a; j <= b; ++j)
		{
			arr[j] = c;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << arr[i] << " ";
	}

	return 0;
}


