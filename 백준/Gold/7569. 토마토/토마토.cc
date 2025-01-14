#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int dx[6] = {1, 0, -1, 0, 0, 0};
const int dy[6] = {0, 1, 0, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

int M, N, H;

// H, N, M
int Graph[105][105][105];

int result = 0;

// z, y, x
queue<tuple<int, int, int>> Q;

bool Check()
{
    for (int z = 0; z < H; ++z)
    {
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (Graph[z][y][x] == 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void bfs()
{
    while (!Q.empty())
    {
        auto [_z, _y, _x] = Q.front();
        Q.pop();

        result = max(result, Graph[_z][_y][_x] - 1);

        for (int dir = 0; dir < 6; ++dir)
        {
            int nz = _z + dz[dir];
            int ny = _y + dy[dir];
            int nx = _x + dx[dir];

            if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M || Graph[nz][ny][nx] != 0)
                continue;

            Q.push(make_tuple(nz, ny, nx));
            Graph[nz][ny][nx] = Graph[_z][_y][_x] + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    bool HasZero = false;
    for (int z = 0; z < H; ++z)
    {
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                int num;
                cin >> num;
                Graph[z][y][x] = num;
                if (num == 0)
                {
                    HasZero = true;
                }
                if (Graph[z][y][x] == 1)
                {
                    Q.push(make_tuple(z, y, x));
                }
            }
        }
    }

    if (!HasZero)
    {
        cout << 0 << '\n';
    }
    else
    {
        bfs();

        if (!Check())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << result << '\n';
        }
    }

    return 0;
}