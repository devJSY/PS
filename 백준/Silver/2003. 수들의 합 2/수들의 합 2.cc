#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[10005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int ed = 0;

    int sum = 0;
    int result = 0;

    for (; st < N; st++)
    {
        while (1)
        {
            if (sum >= M || N <= ed)
                break;

            sum += arr[ed++];
        }

        if (sum == M)
            result++;

        sum -= arr[st];
    }

    cout << result;

    return 0;
}