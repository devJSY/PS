#include <bits/stdc++.h>

using namespace std;

int dp[505][505] = {};
int arr[505][505] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for (size_t i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
        dp[i][i] = dp[i - 1][i - 1] + arr[i][i];

        for (size_t j = 1; j < i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
        }
    }

    int result = 0;
    for (size_t i = 0; i < N; i++)
    {
        result = std::max(result, dp[N - 1][i]);
    }

    cout << result << '\n';

    return 0;
}