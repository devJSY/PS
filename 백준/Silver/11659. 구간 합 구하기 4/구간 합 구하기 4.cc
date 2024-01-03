#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int dp[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    arr[0] = dp[0] = 0;

    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i];
    }

    for (size_t k = 0; k < M; k++)
    {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << '\n';
    }

    return 0;
}