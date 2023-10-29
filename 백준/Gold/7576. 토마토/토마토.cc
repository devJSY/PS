#include <bits/stdc++.h>

using namespace std;

int Map[1005][1005];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<tuple<int, int, int>> Q; // y,x, 일자

	int m, n;
	cin >> m >> n;

	// 처음부터 다 익은 상태인지
	bool flag = true;

	for (size_t y = 1; y <= n; y++)
	{
		for (size_t x = 1; x <= m; x++)
		{
			cin >> Map[y][x];
			if (Map[y][x] == 0) flag = false;
			if (Map[y][x] == 1) Q.push({ y,x,0 });
		}
	}

	if (flag)
	{
		cout << 0 << '\n';
		return 0;
	}

	while (!Q.empty())
	{
		auto t = Q.front();
		Q.pop();

		for (size_t dir = 0; dir < 4; dir++)
		{
			int ny = get<0>(t) + dy[dir];
			int nx = get<1>(t) + dx[dir];

			if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
			if (Map[ny][nx] == 0)
			{
				Q.push({ ny, nx, get<2>(t) + 1 });
				Map[ny][nx] = get<2>(t) + 1;
			}
		}
	}

	int max = -2147000000;

	for (size_t y = 1; y <= n; y++)
	{
		for (size_t x = 1; x <= m; x++)
		{
			if (Map[y][x] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}

			if (Map[y][x] > max) max = Map[y][x];
		}
	}

	cout << max << '\n';

	return 0;
}
