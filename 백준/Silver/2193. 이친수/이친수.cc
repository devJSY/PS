#include <bits/stdc++.h>

using namespace std;

long long dp[100] = {};
long long zeroNum[100] = {};
long long OneNum[100] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    zeroNum[1] = 0;
    OneNum[1] = 1;

    dp[2] = 1;
    zeroNum[2] = 1;
    OneNum[2] = 0;

    for (size_t i = 3; i <= 90; i++)
    {
        dp[i] = (zeroNum[i - 1] * 2) + OneNum[i - 1];
        zeroNum[i] = zeroNum[i - 1] + OneNum[i - 1];
        OneNum[i] = zeroNum[i - 1];
    }

    int N;
    cin >> N;
    cout << dp[N];

    return 0;
}
