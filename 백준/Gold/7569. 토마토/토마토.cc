#include <bits/stdc++.h>
using namespace std;

int board[105][105][105];
int vis[105][105][105];

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int m, n, h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int, int, int, int>> Q; // z,y,x, day

    cin >> m >> n >> h;

    for (size_t height = 0; height < h; height++)
    {
        for (size_t y = 0; y < n; y++)
        {
            fill(vis[height][y], vis[height][y] + m, -1);
        }
    }

    bool flag = true;

    for (size_t height = 0; height < h; height++)
    {
        for (size_t y = 0; y < n; y++)
        {
            for (size_t x = 0; x < m; x++)
            {
                cin >> board[height][y][x];
                if (board[height][y][x] == 1)
                {
                    Q.push({height, y, x, 0});
                    vis[height][y][x] = 0;
                }
                
                 if (board[height][y][x] == 0)
                {
                    flag = false;
                }
            }
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

        for (size_t dir = 0; dir < 6; dir++)
        {
            int nz = get<0>(t) + dz[dir];
            int ny = get<1>(t) + dy[dir];
            int nx = get<2>(t) + dx[dir];

            if (nz < 0 || nz > h || ny < 0 || ny > n || nx < 0 || nx > m)
                continue;
            if (board[nz][ny][nx] == 0 && vis[nz][ny][nx] == -1)
            {
                Q.push({nz, ny, nx, get<3>(t) + 1});
                vis[nz][ny][nx] = get<3>(t) + 1;
            }
        }
    }

    int Max = -1;

    for (size_t height = 0; height < h; height++)
    {
        for (size_t y = 0; y < n; y++)
        {
            for (size_t x = 0; x < m; x++)
            {
                if (vis[height][y][x] == -1 && board[height][y][x] == 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }

                Max = std::max(Max, vis[height][y][x]);
            }
        }
    }

    cout << Max;

    return 0;
}
