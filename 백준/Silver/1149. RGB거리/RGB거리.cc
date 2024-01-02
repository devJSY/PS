#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // value , 0 : R, 1 : G, 2 : B
    vector<vector<int>> vec(N, vector<int>(3));
    vector<vector<int>> dp(N, vector<int>(3));

    for (size_t i = 0; i < N; i++)
    {
        cin >> vec[i][0];
        cin >> vec[i][1];
        cin >> vec[i][2];
    }

    dp[0][0] = vec[0][0];
    dp[0][1] = vec[0][1];
    dp[0][2] = vec[0][2];

    for (size_t i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + vec[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + vec[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + vec[i][2];
    }

    cout << *min_element(dp[N - 1].begin(), dp[N - 1].end());

    return 0;
}