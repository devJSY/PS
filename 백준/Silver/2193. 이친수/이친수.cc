#include <bits/stdc++.h>

using namespace std;

long long dp[100] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;

    dp[2] = 1;

    for (size_t i = 3; i <= 90; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    int N;
    cin >> N;
    cout << dp[N];

    return 0;
}
