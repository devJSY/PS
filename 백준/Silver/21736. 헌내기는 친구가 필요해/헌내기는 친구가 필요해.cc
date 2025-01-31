#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int N, M;
vector<vector<char>> Graph;
vector<vector<bool>> Visited;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    Visited[y][x] = true;

    int ret = 0;
    while (!Q.empty())
    {
        auto [_x, _y] = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = _x + dx[dir];
            int ny = _y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || Visited[ny][nx] || Graph[ny][nx] == 'X')
                continue;

            if (Graph[ny][nx] == 'P')
            {
                ++ret;
            }

            Q.push(make_pair(nx, ny));
            Visited[ny][nx] = true;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Graph.resize(N, vector<char>(M));
    Visited.resize(N, vector<bool>(M, false));

    int x, y;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); ++j)
        {
            Graph[i][j] = str[j];
            if (Graph[i][j] == 'I')
            {
                y = i;
                x = j;
            }
        }
    }

    int ret = bfs(x, y);
    if (ret)
    {
        cout << ret << '\n';
    }
    else
    {
        cout << "TT" << '\n';
    }

    return 0;
}
