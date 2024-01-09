#include <bits/stdc++.h>

using namespace std;

int arr[1005];
int dp[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (size_t i = 2; i <= N; i++)
    {
        for (size_t j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    cout << *max_element(dp, dp + 1001);

    return 0;
}