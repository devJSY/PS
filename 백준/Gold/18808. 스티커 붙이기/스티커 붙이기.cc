#include <bits/stdc++.h>
using namespace std;

int N, M;

bool arr[40][40] = {};

void Attach(int _x, int _y, int _r, int _c, bool sticker[][10])
{
    for (size_t y = 0; y < _r; y++)
    {
        for (size_t x = 0; x < _c; x++)
        {
            if (arr[_y + y][_x + x] == 0 || sticker[y][x] == 1)
                arr[_y + y][_x + x] = sticker[y][x];
        }
    }
}

bool Check2(int _x, int _y, int _r, int _c, bool sticker[][10])
{
    for (size_t y = 0; y < _r; y++)
    {
        for (size_t x = 0; x < _c; x++)
        {
            if (arr[_y + y][_x + x] == 1 && sticker[y][x] == 1)
                return false;
        }
    }

    return true;
}

// dir 0 - 0, 1 - 90, 2 - 180, 3 - 270
void Check1(int r, int c, bool sticker[][10], int dir)
{
    int _y = N - r;
    int _x = M - c;

    if (!(_y < 0 || _x < 0))
    {
        for (size_t y = 0; y <= _y; y++)
        {
            for (size_t x = 0; x <= _x; x++)
            {
                if (Check2(x, y, r, c, sticker))
                {
                    Attach(x, y, r, c, sticker);
                    return;
                }
            }
        }
    }

    if (dir >= 3)
        return;
    else
    {
        // 90도 회전
        bool TurnSticker[10][10] = {};

        for (size_t y = 0; y < r; y++)
        {
            for (size_t x = 0; x < c; x++)
            {
                TurnSticker[x][r - y - 1] = sticker[y][x];
            }
        }

        // 90도 회전하면 행과 열이 서로 바뀌어야함
        Check1(c, r, TurnSticker, dir + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int K = 0;

    cin >> K;

    for (size_t i = 0; i < K; i++)
    {
        int R, C;

        cin >> R >> C;

        bool sticker[10][10] = {};

        for (size_t y = 0; y < R; y++)
        {
            for (size_t x = 0; x < C; x++)
            {
                cin >> sticker[y][x];
            }
        }

        Check1(R, C, sticker, 0);
    }

    int result = 0;

    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < M; x++)
        {
            if (arr[y][x] == 1)
                result++;
        }
    }

    cout << result;

    return 0;
}