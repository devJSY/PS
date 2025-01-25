#include <iostream>

using namespace std;

int N, M;
int ret = 0;

const int MAXRange = 505;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int Graph[MAXRange][MAXRange];
int visited[MAXRange][MAXRange];

void DFS(int x, int y, int Depth, int Sum)
{
    if (Depth == 4)
    {
        ret = max(ret, Sum);
        return;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx])
            continue;

        visited[y][x] = true;
        DFS(nx, ny, Depth + 1, Graph[ny][nx] + Sum);
        visited[y][x] = false;
    }

    // ㅗ ㅏ ㅜ ㅓ 예외처리 x,y 가 가운데 인 경우 기준
    // ㅗ
    if (x - 1 >= 0 && x + 1 <= M && y - 1 >= 0)
    {
        ret = max(ret, Graph[y][x] + Graph[y][x - 1] + Graph[y][x + 1] + Graph[y - 1][x]);
    }
    // ㅏ
    if (x + 1 <= M && y - 1 >= 0 && y + 1 <= N)
    {
        ret = max(ret, Graph[y][x] + Graph[y - 1][x] + Graph[y + 1][x] + Graph[y][x + 1]);
    }
    // ㅜ
    if (x - 1 >= 0 && x + 1 <= M && y + 1 <= N)
    {
        ret = max(ret, Graph[y][x] + Graph[y][x - 1] + Graph[y][x + 1] + Graph[y + 1][x]);
    }
    // ㅓ
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 <= N)
    {
        ret = max(ret, Graph[y][x] + Graph[y - 1][x] + Graph[y + 1][x] + Graph[y][x - 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Graph[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            visited[i][j] = true;
            DFS(j, i, 1, Graph[i][j]);
            visited[i][j] = false;
        }
    }

    cout << ret << '\n';

    return 0;
}