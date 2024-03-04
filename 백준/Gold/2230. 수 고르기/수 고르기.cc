#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int st = 0;
    int ed = 0;
    int min = 0x7fffffff;

    cin >> N >> M;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    while (1)
    {
        if (st >= N || ed >= N)
            break;

        if (arr[ed] - arr[st] < M)
        {
            ed += 1;
        }
        else
        {
            min = std::min(min, arr[ed] - arr[st]);
            st += 1;
        }
    }

    cout << min;

    return 0;
}