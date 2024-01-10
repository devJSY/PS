#include <bits/stdc++.h>

using namespace std;

long long dp[105] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (size_t i = 4; i <= 102; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}