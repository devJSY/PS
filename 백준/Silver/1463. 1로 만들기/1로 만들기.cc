#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> DP(N + 1);

    for (int i = 0; i <= N; ++i)
    {
        DP[i] = i;
    }

    DP[1] = 0;

    for (int i = 2; i <= N; ++i)
    {
        if (i % 3 == 0)
        {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }

        if (i % 2 == 0)
        {
            DP[i] = min(DP[i], DP[i / 2] + 1);
        }

        DP[i] = min(DP[i], DP[i - 1] + 1);
    }

    cout << DP[N] << '\n';

    return 0;
}
