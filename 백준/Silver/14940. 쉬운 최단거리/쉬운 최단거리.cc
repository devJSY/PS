#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int StartX, StartY;

int N, M;
const int INF = 987654321;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int Graph[1005][1005];
int Result[1005][1005];

void bfs()
{
    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(StartX, StartY, 0));

    while (!Q.empty())
    {
        auto [x, y, dist] = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || Graph[ny][nx] != 1)
                continue;

            if (Result[ny][nx] > dist + 1)
            {
                Result[ny][nx] = dist + 1;
                Q.push(make_tuple(nx, ny, dist + 1));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            cin >> Graph[y][x];
            Result[y][x] = INF; // INF 값 초기화

            if (Graph[y][x] == 2)
            {
                StartY = y;
                StartX = x;
                Result[y][x] = 0;
            }

            // 원래 갈 수 없는 곳
            if (Graph[y][x] == 0)
            {
                Result[y][x] = 0;
            }
        }
    }

    bfs();

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {

            if (Result[y][x] == INF)
            {
                cout << -1 << " ";
            }
            else
            {

                cout << Result[y][x] << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}