#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M;

int d[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 1; i <= N; i++)
    {
        std::fill(d[i], d[i] + 1 + N, INF);
    }

    for (size_t i = 0; i < M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        d[a][b] = std::min(d[a][b], cost);
    }

    for (size_t i = 1; i <= N; i++)
    {
        d[i][i] = 0;
    }

    for (size_t k = 1; k <= N; k++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            for (size_t j = 1; j <= N; j++)
            {
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            if (d[i][j] == INF)
                cout << "0 ";
            else
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}