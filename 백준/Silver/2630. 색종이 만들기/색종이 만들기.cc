#include <bits/stdc++.h>
using namespace std;

bool board[150][150];

int N = 0;
int White = 0;
int Blue = 0;

bool CheckBoard(int x, int y, int n)
{
    for (size_t i = y; i < y + n; i++)
    {
        for (size_t j = x; j < x + n; j++)
        {
            if (board[i][j] != board[y][x])
                return false;
        }
    }

    return true;
}

void recursion(int x, int y, int n)
{
    if (CheckBoard(x, y, n))
    {
        if (board[y][x] == 1)
            Blue++;
        else if (board[y][x] == 0)
            White++;

        return;
    }

    int half = n / 2.f;

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            recursion(x + j * half, y + i * half, half);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < N; x++)
        {
            cin >> board[y][x];
        }
    }

    recursion(0, 0, N);

    cout << White << '\n';
    cout << Blue << '\n';

    return 0;
}
