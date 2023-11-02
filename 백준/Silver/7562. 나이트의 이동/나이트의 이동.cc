#include <bits/stdc++.h>

using namespace std;

int board[305][305];

int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios::sync_with_stdio;
    cin.tie(0);

    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        int l;
        cin >> l;

        for (size_t j = 0; j < 301; j++)
        {
            fill(board[j], board[j] + 300, -1);
        }

        pair<int, int> start;
        pair<int, int> dest;

        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;

        // 목적지
        board[start.first][start.second] = 0;
        board[dest.first][dest.second] = 9999;

        int result = 0;

        queue<tuple<int, int, int>> Q;
        Q.push({start.first, start.second, 0});

        while (!Q.empty())
        {
            auto t = Q.front();
            Q.pop();
            if (board[get<0>(t)][get<1>(t)] == 9999)
            {
                result = get<2>(t);
                break;
            }

            for (size_t dir = 0; dir < 8; dir++)
            {
                int ny = get<0>(t) + dy[dir];
                int nx = get<1>(t) + dx[dir];

                if (ny < 0 || ny >= l || nx < 0 || nx >= l)
                    continue;
                if (board[ny][nx] < 0)
                {
                    Q.push({ny, nx, get<2>(t) + 1});
                    board[ny][nx] = get<2>(t) + 1;
                }

                if (board[ny][nx] == 9999)
                {
                    Q.push({ny, nx, get<2>(t) + 1});
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}
