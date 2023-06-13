#include <iostream>

using namespace std;

int main()
{
	int IdxY = 0;
	int IdxX = 0;

	int max = -2147000000;
	int arr[10][10] = {};

	for (int y = 1; y < 10; y++)
	{
		for (int x = 1; x < 10; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int y = 1; y < 10; y++)
	{
		for (int x = 1; x < 10; x++)
		{
			if (max < arr[y][x])
			{
				max = arr[y][x];
				IdxY = y;
				IdxX = x;
			}
		}
	}

	cout << max << endl;
	cout << IdxY << " " << IdxX << endl;

    return 0;
}
