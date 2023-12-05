#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[8][8];
int result = 100;

// dir
// 0 : 오른쪽
// 1 : 왼쪽
// 2 : 위
// 3 : 아래

pair<int, int> GetNextSpot(int _x, int _y)
{
    int x = _x + 1;
    int y = _y;

    if (x >= M)
    {
        x = 0;
        y += 1;
    }

    return {x, y};
}

// flag - true 면 # 체크 false 0으로 복귀
void CheckArr(int _x, int _y, int dir, bool flag, int offset)
{
    if (_x < 0 || _x >= M || _y < 0 || _y >= N || arr[_y][_x] == '6')
        return;

    if (flag)
    {
        if (arr[_y][_x] <= '0')
        {
            arr[_y][_x] -= offset + 1;
        }
    }
    else
    {
        if (arr[_y][_x] <= '0')
        {
            arr[_y][_x] += offset + 1;
        }
    }

    if (dir == 0)
        CheckArr(_x + 1, _y, dir, flag, offset);
    else if (dir == 1)
        CheckArr(_x - 1, _y, dir, flag, offset);
    else if (dir == 2)
        CheckArr(_x, _y - 1, dir, flag, offset);
    else if (dir == 3)
        CheckArr(_x, _y + 1, dir, flag, offset);
}

int CountBlindSpot()
{
    int cnt = 0;

    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < M; x++)
        {
            if (arr[y][x] == '0')
                cnt++;
        }
    }

    return cnt;
}

void DFS(int x, int y)
{
    if (x >= M || y >= N)
    {
        result = std::min(result, CountBlindSpot());
        return;
    }

    auto t = GetNextSpot(x, y);

    if (arr[y][x] == '1')
    {
        CheckArr(x + 1, y, 0, true, 0);
        DFS(t.first, t.second);
        CheckArr(x + 1, y, 0, false, 0);

        CheckArr(x, y + 1, 3, true, 1);
        DFS(t.first, t.second);
        CheckArr(x, y + 1, 3, false, 1);

        CheckArr(x - 1, y, 1, true, 2);
        DFS(t.first, t.second);
        CheckArr(x - 1, y, 1, false, 2);

        CheckArr(x, y - 1, 2, true, 3);
        DFS(t.first, t.second);
        CheckArr(x, y - 1, 2, false, 3);
    }
    else if (arr[y][x] == '2')
    {
        CheckArr(x + 1, y, 0, true, 0);
        CheckArr(x - 1, y, 1, true, 1);
        DFS(t.first, t.second);
        CheckArr(x - 1, y, 1, false, 1);
        CheckArr(x + 1, y, 0, false, 0);

        CheckArr(x, y - 1, 2, true, 0);
        CheckArr(x, y + 1, 3, true, 1);
        DFS(t.first, t.second);
        CheckArr(x, y + 1, 3, false, 1);
        CheckArr(x, y - 1, 2, false, 0);
    }
    else if (arr[y][x] == '3')
    {
        CheckArr(x, y - 1, 2, true, 0);
        CheckArr(x + 1, y, 0, true, 1);
        DFS(t.first, t.second);
        CheckArr(x + 1, y, 0, false, 1);
        CheckArr(x, y - 1, 2, false, 0);

        CheckArr(x + 1, y, 0, true, 0);
        CheckArr(x, y + 1, 3, true, 1);
        DFS(t.first, t.second);
        CheckArr(x, y + 1, 3, false, 1);
        CheckArr(x + 1, y, 0, false, 0);

        CheckArr(x, y + 1, 3, true, 0);
        CheckArr(x - 1, y, 1, true, 1);
        DFS(t.first, t.second);
        CheckArr(x - 1, y, 1, false, 1);
        CheckArr(x, y + 1, 3, false, 0);

        CheckArr(x - 1, y, 1, true, 0);
        CheckArr(x, y - 1, 2, true, 1);
        DFS(t.first, t.second);
        CheckArr(x, y - 1, 2, false, 1);
        CheckArr(x - 1, y, 1, false, 0);
    }
    else if (arr[y][x] == '4')
    {
        CheckArr(x + 1, y, 0, true, 0);
        CheckArr(x - 1, y, 1, true, 1);
        CheckArr(x, y - 1, 2, true, 2);
        DFS(t.first, t.second);
        CheckArr(x, y - 1, 2, false, 2);
        CheckArr(x - 1, y, 1, false, 1);
        CheckArr(x + 1, y, 0, false, 0);

        CheckArr(x + 1, y, 0, true, 0);
        CheckArr(x, y + 1, 3, true, 1);
        CheckArr(x, y - 1, 2, true, 2);
        DFS(t.first, t.second);
        CheckArr(x, y - 1, 2, false, 2);
        CheckArr(x, y + 1, 3, false, 1);
        CheckArr(x + 1, y, 0, false, 0);

        CheckArr(x + 1, y, 0, true, 0);
        CheckArr(x, y + 1, 3, true, 1);
        CheckArr(x - 1, y, 1, true, 2);
        DFS(t.first, t.second);
        CheckArr(x - 1, y, 1, false, 2);
        CheckArr(x, y + 1, 3, false, 1);
        CheckArr(x + 1, y, 0, false, 0);

        CheckArr(x, y + 1, 3, true, 0);
        CheckArr(x - 1, y, 1, true, 1);
        CheckArr(x, y - 1, 2, true, 2);
        DFS(t.first, t.second);
        CheckArr(x, y - 1, 2, false, 2);
        CheckArr(x - 1, y, 1, false, 1);
        CheckArr(x, y + 1, 3, false, 0);
    }
    else if (arr[y][x] == '5')
    {
        CheckArr(x + 1, y, 0, true, 0);
        CheckArr(x, y + 1, 3, true, 1);
        CheckArr(x - 1, y, 1, true, 2);
        CheckArr(x, y - 1, 2, true, 3);
        DFS(t.first, t.second);
        CheckArr(x + 1, y, 0, false, 0);
        CheckArr(x, y + 1, 3, false, 1);
        CheckArr(x - 1, y, 1, false, 2);
        CheckArr(x, y - 1, 2, false, 3);
    }
    else
    {
        DFS(t.first, t.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < M; x++)
        {
            cin >> arr[y][x];
        }
    }

    DFS(0, 0);

    cout << result;

    return 0;
}