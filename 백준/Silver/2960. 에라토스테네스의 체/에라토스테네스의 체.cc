#include <bits/stdc++.h>

using namespace std;

bool arr[1005] = {};
int result[1005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    arr[0] = arr[1] = true;

    int idx = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            if (arr[j])
                continue;

            arr[j] = true;
            result[idx++] = j;
        }
    }

    cout << result[K];

    return 0;
}