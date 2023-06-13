#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int m = 0;

	int arr[101][101] = {};

	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int a = 0;
			cin >> a;
			arr[y][x] += a;
		}
	}


	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

    return 0;
}
