#include <bits/stdc++.h>
using namespace std;

char board[101][101];
int vis[101][101];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int n;

void BFS(int y, int x, char ch)
{
    queue<pair<int, int>> Q;

    Q.push({y, x});

    while (!Q.empty())
    {
        auto t = Q.front();
        Q.pop();

        for (size_t dir = 0; dir < 4; dir++)
        {
            int ny = t.first + dy[dir];
            int nx = t.second + dx[dir];

            if (ny < 0 || ny > n || nx < 0 || nx > n)
                continue;
            if (board[ny][nx] == ch && vis[ny][nx] == false)
            {
                vis[ny][nx] = 1;
                Q.push({ny, nx});
            }
        }
    }
}

void BFS_red_green(int y, int x, char ch)
{
    queue<pair<int, int>> Q;

    Q.push({y, x});

    while (!Q.empty())
    {
        auto t = Q.front();
        Q.pop();

        for (size_t dir = 0; dir < 4; dir++)
        {
            int ny = t.first + dy[dir];
            int nx = t.second + dx[dir];

            if (ny < 0 || ny > n || nx < 0 || nx > n)
                continue;

            if (ch == 'B')
            {
                if (board[ny][nx] == 'B' && vis[ny][nx] == false)
                {
                    vis[ny][nx] = 1;
                    Q.push({ny, nx});
                }
            }
            else
            {
                if (board[ny][nx] == 'R' || board[ny][nx] == 'G')
                {
                    if (vis[ny][nx] == false)
                    {
                        vis[ny][nx] = 1;
                        Q.push({ny, nx});
                    }
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            cin >> board[y][x];
        }
    }

    // 적록색약이 아닌사람
    int cnt = 0;
    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            if (vis[y][x] == 0)
            {
                cnt++;
                vis[y][x] = 1;
                BFS(y, x, board[y][x]);
            }
        }
    }

    cout << cnt << " ";

    // 방문여부 초기화
    for (size_t i = 0; i < n; i++)
    {
        fill(vis[i], vis[i] + n, 0);
    }

    // 적록색약인 사람
    cnt = 0;
    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            if (vis[y][x] == 0)
            {
                cnt++;
                vis[y][x] = 1;
                BFS_red_green(y, x, board[y][x]);
            }
        }
    }

    cout << cnt;

    return 0;
}
