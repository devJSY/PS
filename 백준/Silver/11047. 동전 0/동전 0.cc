#include <bits/stdc++.h>

using namespace std;

int arr[15] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    cin >> N >> K;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int idx = N - 1;
    int result = 0;

    while (idx >= 0)
    {
        if (arr[idx] > K)
        {
            idx--;
            continue;
        }

        result += K / arr[idx];
        K %= arr[idx];
    }

    cout << result;

    return 0;
}