#include <bits/stdc++.h>

using namespace std;

int N;
int arr[105][105];
int vist[105][105];

int result = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS()
{
    int cnt = 0;
    queue<pair<int, int>> Q;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (vist[y][x])
                continue;

            Q.push(make_pair(y, x));
            vist[y][x] = 1;
            ++cnt;

            while (!Q.empty())
            {
                int _y, _x;
                tie(_y, _x) = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = _x + dx[dir];
                    int ny = _y + dy[dir];

                    if (vist[ny][nx] || nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;

                    Q.push(make_pair(ny, nx));
                    vist[ny][nx] = 1;
                }
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int MaxNum = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> arr[y][x];
            MaxNum = std::max(arr[y][x], MaxNum);
        }
    }

    for (int i = 0; i <= MaxNum; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::fill(vist[j], vist[j] + N, 0);
        }

        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < N; ++x)
            {
                if (arr[y][x] <= i)
                    vist[y][x] = 1;
            }
        }

        result = std::max(result, BFS());
    }

    cout << result;

    return 0;
}
