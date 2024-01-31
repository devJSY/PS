#include <bits/stdc++.h>

using namespace std;

bool primes[1000005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    primes[0] = primes[1] = true;

    for (int i = 2; i * i <= M; i++)
    {
        if (primes[i])
            continue;
        else
        {
            for (int j = 2; j * i <= M; j++)
            {
                primes[i * j] = true;
            }
        }
    }

    for (int i = N; i <= M; i++)
    {
        if (!primes[i])
            cout << i << '\n';
    }

    return 0;
}