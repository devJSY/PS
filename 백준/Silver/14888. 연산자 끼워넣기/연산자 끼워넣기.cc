#include <iostream>

using namespace std;

int arr[12] = {};
int oper[4] = {};

int Min = 2147000000;
int Max = -2147000000;

void DFS(int L, int leaf, int cal)
{
	if (L > leaf)
	{
		if (cal > Max) Max = cal;
		if (cal < Min) Min = cal;

		return;
	}
	else
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (oper[i] > 0)
			{
				oper[i]--;
				if (i == 0)
					DFS(L + 1, leaf, cal + arr[L]);
				else if (i == 1)
					DFS(L + 1, leaf, cal - arr[L]);
				else if (i == 2)
					DFS(L + 1, leaf, cal * arr[L]);
				else if (i == 3)
					DFS(L + 1, leaf, cal / arr[L]);
				oper[i]++;				
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int leaf = 0;

	for (size_t i = 0; i < 4; i++)
	{
		cin >> oper[i];
		leaf += oper[i];
	}

	DFS(1, leaf, arr[0]);

	cout << Max << '\n';
	cout << Min << '\n';

	return 0;
}