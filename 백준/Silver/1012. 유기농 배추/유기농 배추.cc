#include <bits/stdc++.h>
using namespace std;

int board[100][100];
int dist[100][100];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        int m, n, k;
        cin >> m >> n >> k;

        queue<pair<int, int>> Q;

        for (size_t j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int cnt = 0;

        for (size_t y = 0; y < n; y++)
        {
            for (size_t x = 0; x < m; x++)
            {
                if (dist[y][x] == 0 && board[y][x] == 1)
                {
                    dist[y][x] = 1;
                    Q.push({y, x});
                    cnt++;
                }

                while (!Q.empty())
                {
                    auto t = Q.front();
                    Q.pop();

                    for (size_t dir = 0; dir < 4; dir++)
                    {
                        int ny = t.first + dy[dir];
                        int nx = t.second + dx[dir];

                        if (ny < 0 || ny > n || nx < 0 || nx > m)
                            continue;
                        if (dist[ny][nx] == 0 && board[ny][nx] == 1)
                        {
                            dist[ny][nx] = 1;
                            Q.push({ny, nx});
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';

        for (size_t y = 0; y < 51; y++)
        {
            for (size_t x = 0; x < 51; x++)
            {
                board[y][x] = 0;
                dist[y][x] = 0;
            }
        }
    }

    return 0;
}
