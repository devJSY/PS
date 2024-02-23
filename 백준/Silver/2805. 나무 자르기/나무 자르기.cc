#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1000005] = {};

bool solve(int x)
{
    long long cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (x >= arr[i])
            continue;

        cnt += arr[i] - x;
    }

    return cnt >= M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int ed = *max_element(arr, arr + N);

    while (st < ed)
    {
        int mid = (st + ed + 1) / 2;

        if (solve(mid))
            st = mid;
        else
            ed = mid - 1;
    }

    cout << st;

    return 0;
}