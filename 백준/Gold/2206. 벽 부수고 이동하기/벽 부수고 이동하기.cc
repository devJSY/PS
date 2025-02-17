#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <tuple>

using namespace std;

int N, M;
vector<vector<int>> adj;
int result[2][1005][1005];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int bfs()
{
    // X, Y, 벽을 부술 순적이 있는지
    queue<tuple<int, int, bool>> Q;
    Q.push({0, 0, false});
    result[0][0][0] = 1;
    result[1][0][0] = 1;

    while (!Q.empty())
    {
        auto [x, y, isBreak] = Q.front();
        Q.pop();

        if (x == M - 1 && y == N - 1)
        {
            return result[isBreak][N - 1][M - 1];
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;

            if (0 == adj[ny][nx] && 0 == result[isBreak][ny][nx])
            {
                result[isBreak][ny][nx] = result[isBreak][y][x] + 1;
                Q.push(make_tuple(nx, ny, isBreak));
            }
            else if (1 == adj[ny][nx] && !isBreak && 0 == result[1][ny][nx])
            {
                result[1][ny][nx] = result[0][y][x] + 1;
                Q.push(make_tuple(nx, ny, true));
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    adj.resize(N, vector<int>(M, 0));

    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;

        for (int j = 0; j < str.size(); ++j)
        {
            adj[i][j] = str[j] - '0';
        }
    }

    cout << bfs() << '\n';

    return 0;
}
