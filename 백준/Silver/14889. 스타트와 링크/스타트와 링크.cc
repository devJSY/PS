#include <iostream>

using namespace std;

int n = 0;
int arr[21][21] = {};
int ch[21] = {};
int result = 2147000000;

void DFS(int L, int pos)
{
	if (L == n / 2)
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (ch[i] == true && ch[j] == true) start += arr[i][j];
				if (ch[i] == false && ch[j] == false) link += arr[i][j];
			}
		}

		if (abs(start - link) < result) result = abs(start - link);

		return;
	}
	else
	{
		for (size_t i = pos; i < n; i++)
		{
			ch[i] = 1;
			DFS(L + 1, i + 1);
			ch[i] = 0;		
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (size_t y = 0; y < n; y++)
	{
		for (size_t x = 0; x < n; x++)
		{
			cin >> arr[y][x];
		}
	}

	DFS(0, 1);

	cout << result << '\n';

	return 0;
}