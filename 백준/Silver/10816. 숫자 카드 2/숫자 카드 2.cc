#include <bits/stdc++.h>

using namespace std;

int arr[500005] = {};
int N, M;

int upper_Idx(int len, int val)
{
    int st = 0;
    int en = len;

    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] > val)
            en = mid;
        else
            st = mid + 1;
    }

    return st;
}

int lower_Idx(int len, int val)
{
    int st = 0;
    int en = len;

    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] >= val)
            en = mid;
        else
            st = mid + 1;
    }

    return st;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cin >> M;

    for (size_t i = 0; i < M; i++)
    {
        int val;
        cin >> val;
        cout << upper_Idx(N, val) - lower_Idx(N, val) << " ";
    }

    return 0;
}