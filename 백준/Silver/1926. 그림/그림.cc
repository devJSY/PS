#include <bits/stdc++.h>

using namespace std;

int ch[505][505];
int arr[505][505];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> Q;

	int n, m;
	cin >> n >> m;

	for (size_t y = 0; y < n; y++)
	{
		for (size_t x = 0; x < m; x++)
		{
			cin >> arr[y][x];
		}
	}

	int cnt = 0;
	int max = 0;

	for (size_t y = 0; y < n; y++)
	{
		for (size_t x = 0; x < m; x++)
		{
			if (arr[y][x] == 1 && ch[y][x] == 0)
			{
				cnt++;
				ch[y][x] = 1;
				Q.push({ y, x });

				int maxCnt = 0;

				while (!Q.empty())
				{
					++maxCnt;

					auto t = Q.front();
					Q.pop();

					for (size_t dir = 0; dir < 4; dir++)
					{
						int nx = t.second + dx[dir];
						int ny = t.first + dy[dir];

						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (ch[ny][nx] || arr[ny][nx] == 0) continue;

						ch[ny][nx] = 1;
						Q.push({ ny, nx });
					}
				}

				if (maxCnt > max) max = maxCnt;
			}
		}
	}

	cout << cnt << '\n' << max;

	return 0;
}
