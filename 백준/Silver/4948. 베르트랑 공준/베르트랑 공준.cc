#include <bits/stdc++.h>

using namespace std;

int N = 123456.f * 2.f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> primes(N + 1, true);

    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (!primes[i])
            continue;

        for (int j = i + i; j <= N; j += i)
        {
            primes[j] = false;
        }
    }

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        int result = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (!primes[i])
                continue;

            result++;
        }

        cout << result << '\n';
    }

    return 0;
}