#include <iostream>

using namespace std;

int n = 0;
int m = 0;

int ch[10] = {};
int result[10] = {};

void DFS(int L)
{
	if (L == m)
	{
		for (size_t i = 0; i < L; i++)
		{
			cout << result[i] << ' ';
		}
		cout << '\n';

		return;
	}
	else
	{
		for (size_t i = 1; i <= n; i++)
		{
			if (ch[i] == 0)
			{
				result[L] = i;
				ch[i] = 1;
				DFS(L + 1);
				ch[i] = 0;
				result[L] = 0;
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

	DFS(0);

	return 0;
}