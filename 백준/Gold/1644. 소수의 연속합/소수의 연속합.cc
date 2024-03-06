#include <bits/stdc++.h>

using namespace std;

int N;
bool primes[4000005] = {};
int primeNums[4000005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    primes[0] = primes[1] = true;

    for (int i = 2; i * i <= 4000000; i++)
    {
        if (primes[i])
            continue;

        for (int j = i + i; j <= 4000000; j += i)
        {
            primes[j] = true;
        }
    }

    int idx = 0;
    for (int i = 0; i < 4000000; i++)
    {
        if (!primes[i])
        {
            primeNums[idx++] = i;
        }
    }

    int st = 0;
    int ed = 0;
    int tot = 0;

    int result = 0;

    for (; st <= std::min(idx, N); st++)
    {
        while (tot < N)
        {
            tot += primeNums[ed];
            ed++;
        }

        if (tot == N)
            result++;

        tot -= primeNums[st];
    }

    cout << result;

    return 0;
}