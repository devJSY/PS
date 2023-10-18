#include <iostream>
#include <limits>

using namespace std;

int ChackArr(char origin[][50], char comp[][9], int x, int y)
{
	int count = 0;

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (origin[i + y][j + x] != comp[i][j])
			{
				count++;
			}
		}
	}

	return count;
}

int main()
{
	char white[8][9] =
	{
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	};

	char Black[8][9] =
	{
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	};

	char arr[50][50];

	int n, m;

	cin >> n >> m;

	for (size_t y = 0; y < n; y++)
	{
		for (size_t x = 0; x < m; x++)
		{
			cin >> arr[y][x];
		}
	}

	int result = numeric_limits<int>::max();

	for (size_t y = 0; y <= n - 8; y++)
	{
		for (size_t x = 0; x <= m - 8; x++)
		{
			result = std::min(result, std::min(ChackArr(arr, white, x, y), ChackArr(arr, Black, x, y)));
		}
	}

	cout << result << endl;

	return 0;
}

