#include <bits/stdc++.h>

using namespace std;

int arr[100005] = {};
int dp[100005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;


    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int result = dp[0];

    for (size_t i = 1; i < N; i++)
    {
        dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
        result = std::max(dp[i], result);
    }

    cout << result;

    return 0;
}