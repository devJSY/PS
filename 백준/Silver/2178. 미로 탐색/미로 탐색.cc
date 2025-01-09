#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> vec(N, vector<bool>(M, false));

    for (int y = 0; y < N; ++y)
    {
        string str;
        cin >> str;
        for (int x = 0; x < M; ++x)
        {
            vec[y][x] = str[x] - '0';
        }
    }

    // X, Y, dist
    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(0, 0, 1));
    int ret = 987654321;
    vec[0][0] = false;

    while (!Q.empty())
    {
        auto [x, y, dist] = Q.front();
        Q.pop();

        if (x == M - 1 && y == N - 1)
        {
            ret = min(ret, dist);
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || !vec[ny][nx])
                continue;

            Q.push(make_tuple(nx, ny, dist + 1));
            vec[ny][nx] = false;
        }
    }

    cout << ret << '\n';

    return 0;
}