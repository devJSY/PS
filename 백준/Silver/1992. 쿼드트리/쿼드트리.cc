#include <bits/stdc++.h>
using namespace std;

int board[70][70];

int N;

bool Check(int x, int y, int n)
{
    for (size_t i = y; i < y + n; i++)
    {
        for (size_t j = x; j < x + n; j++)
        {
            if (board[y][x] != board[i][j])
                return false;
        }
    }

    return true;
}

void Recursion(int x, int y, int n)
{
    if (n <= 0)
        return;

    if (Check(x, y, n))
    {
        cout << board[y][x];
        return;
    }

    cout << '(';
    int half = n / 2;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            Recursion(x + j * half, y + i * half, half);
        }
    }
    cout << ')';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        string str;

        cin >> str;
        int idx = 0;

        for (char ch : str)
        {
            board[i][idx++] = ch - '0';
        }
    }

    Recursion(0, 0, N);

    return 0;
}
