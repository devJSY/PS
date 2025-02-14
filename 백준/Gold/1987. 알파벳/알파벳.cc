#include <iostream>

using namespace std;

int R, C;
char Board[25][25];
bool Visited[100];
int ret = 0;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y, int Cnt)
{
    ret = max(ret, Cnt);

    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R || Visited[Board[ny][nx] - 'A'])
            continue;

        Visited[Board[ny][nx] - 'A'] = true;
        DFS(nx, ny, Cnt + 1);
        Visited[Board[ny][nx] - 'A'] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> Board[i][j];
        }
    }

    Visited[Board[0][0] - 'A'] = true;
    DFS(0, 0, 1);

    cout << ret << '\n';

    return 0;
}
