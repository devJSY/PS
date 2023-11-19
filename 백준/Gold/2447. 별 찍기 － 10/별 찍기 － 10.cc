#include <bits/stdc++.h>

using namespace std;

char board[2200][2200];

int N;

void Recursion(int n, int x, int y)
{
    if (n <= 0)
    {
        board[y][x] = '*';
        return;
    }

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;

            Recursion(n / 3, x + j * (n / 3), y + i * (n / 3));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        fill(board[i], board[i] + N, ' ');
    }

    Recursion(N, 0, 0);


    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
