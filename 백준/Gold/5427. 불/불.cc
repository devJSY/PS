#include <bits/stdc++.h>

using namespace std;

char board[1005][1005];

int visited1[1005][1005];
int visited2[1005][1005];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (size_t i = 0; i < t; i++)
	{
		int w, h;
		cin >> w >> h;

		for (size_t j = 0; j < h; j++)
		{
			fill(board[j], board[j] + w, 0);
			fill(visited1[j], visited1[j] + w, -1);
			fill(visited2[j], visited2[j] + w, -1);
		}

		queue < pair<int, int>> Q1;
		queue < pair<int, int>> Q2;

		for (size_t y = 0; y < h; y++)
		{
			for (size_t x = 0; x < w; x++)
			{
				cin >> board[y][x];

				if (board[y][x] == '*')
				{
					visited1[y][x] = 0;
					Q1.push({ y,x });
				}

				if (board[y][x] == '@')
				{
					visited2[y][x] = 0;
					Q2.push({ y,x });
				}
			}
		}

		// fire
		while (!Q1.empty())
		{
			pair<int, int> t = Q1.front();
			Q1.pop();

			for (size_t dir = 0; dir < 4; dir++)
			{
				int ny = t.first + dy[dir];
				int nx = t.second + dx[dir];

				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (board[ny][nx] != '#' && visited1[ny][nx] < 0)
				{
					visited1[ny][nx] = visited1[t.first][t.second] + 1;
					Q1.push({ ny,nx });
				}
			}
		}

		while (!Q2.empty())
		{
			pair<int, int> t = Q2.front();


			if (t.first == 0 || t.first == h - 1 || t.second == 0 || t.second == w - 1)
			{
				cout << visited2[t.first][t.second] + 1 << '\n';
				break;
			}

			Q2.pop();

			for (size_t dir = 0; dir < 4; dir++)
			{
				int ny = t.first + dy[dir];
				int nx = t.second + dx[dir];

				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (board[ny][nx] != '#' && visited2[ny][nx] < 0)
				{
					if (visited1[ny][nx] == -1 || visited1[ny][nx] > visited2[t.first][t.second] + 1)
					{
						visited2[ny][nx] = visited2[t.first][t.second] + 1;
						Q2.push({ ny,nx });
					}
				}
			}
		}

		if (Q2.empty())
		{
			cout << "IMPOSSIBLE" << '\n';
		}
	}
	return 0;
}
