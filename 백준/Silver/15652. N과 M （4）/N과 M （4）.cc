#include <iostream>

using namespace std;

int n = 0;
int m = 0;

int arr[10] = {};

void DFS(int L, int idx)
{
	if (L == m)
	{
		for (size_t i = 0; i < L; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else
	{
		for (int i = idx; i <= n; i++)
		{
			arr[L] = i;
			DFS(L + 1, i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	DFS(0, 1);

	return 0;
}