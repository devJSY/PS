#include <iostream>

using namespace std;

bool visited[10] = {};
int arr[10] = {};

int n = 0;
int m = 0;

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
		for (size_t i = idx; i <= n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				arr[L] = i;
				DFS(L + 1, i);
				visited[i] = false;
			}
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