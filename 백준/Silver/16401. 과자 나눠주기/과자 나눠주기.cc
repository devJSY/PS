#include <bits/stdc++.h>

using namespace std;

int M, N;
int arr[1000005] = {};

bool solve(int x)
{
    int cnt = 0;
    for (size_t i = 0; i < N; i++)
    {
        cnt += arr[i] / x;
    }

    return cnt >= M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long long st = 0;
    long long ed = 0x7fffffff;

    while (st < ed)
    {
        long long mid = (st + ed + 1) / 2;
        if (solve(mid))
        {
            st = mid;
        }
        else
        {
            ed = mid - 1;
        }
    }

    cout << st;

    return 0;
}