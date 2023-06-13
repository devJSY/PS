#include <iostream>

using namespace std;

int arr[101][101] = {};

int main()
{
	int n = 0;
	cin >> n;

	int InY = 0;
	int InX = 0;
	
	for (size_t i = 0; i < n; i++)
	{
		cin >> InY >> InX;

		for (int y = InY; y < InY + 10; y++)
		{
			for (int x = InX; x < InX + 10; x++)
			{
				arr[y][x] = 1;
			}
		}
	}

	int cnt = 0;
	
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			if (arr[y][x] == 1) cnt++;
		}
	}

	cout << cnt;
	

    return 0;
}
