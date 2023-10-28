#include <bits/stdc++.h>

using namespace std;

int ch[105][105];
int arr[105][105];

int dx[4] = { 0, 1, 0 ,-1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<pair<int, int>, int>> Q;

	int n, m;
	cin >> n >> m;

	for (size_t y = 1; y <= n; y++)
	{
		string num;
		cin >> num;

		int idx = 1;
		for (char ch : num)
		{
			arr[y][idx++] = ch - '0';
		}
	}

	ch[1][1] = 1;
	Q.push({ {1,1}, 1 });

	while (!Q.empty())
	{
		auto t = Q.front();
		Q.pop();

		for (size_t dir = 0; dir < 4; dir++)
		{
			int ny = t.first.first + dy[dir];
			int nx = t.first.second + dx[dir];

			if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
			if (ch[ny][nx] || arr[ny][nx] == 0) continue;

			if (ny == n && nx == m)
			{
				cout << t.second + 1;
				return 0;
			}

			ch[ny][nx] = 1;
			Q.push({ {ny, nx}, t.second + 1 });
		}
	}

	return 0;
}
