#include <bits/stdc++.h>

using namespace std;

int board[1005][1005];
int dist[2][1005][1005];
int n, m;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (size_t y = 1; y <= n; y++)
	{
		string str;
		cin >> str;

		for (size_t x = 0; x < str.size(); x++)
		{
			board[y][x + 1] = str[x] - '0';
		}
	}

	queue<tuple<int, int, int>> Q;
	Q.push({ 1,1,0 });

	while (!Q.empty())
	{
		int y, x, broken;

		tie(y, x, broken) = Q.front();

		if (y == n && x == m)
		{
			cout << dist[broken][y][x] + 1;
			break;
		}

		Q.pop();

		for (size_t dir = 0; dir < 4; dir++)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m) continue;

			if (board[ny][nx] == 0 && dist[broken][ny][nx] == 0)
			{
				dist[broken][ny][nx] = dist[broken][y][x] + 1;
				Q.push({ny,nx, broken});
			}

			if (broken == 0 && board[ny][nx] == 1 && dist[1][ny][nx] == 0)
			{
				dist[1][ny][nx] = dist[broken][y][x] + 1;
				Q.push({ ny,nx, 1 });
			}
		}
	}

	if (Q.empty())
	{
		cout << -1;
	}




	return 0;
}
