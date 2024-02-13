#include <bits/stdc++.h>

using namespace std;

int answer[100005] = {};
int arr[100005] = {};

bool binarySearch(int _st, int _ed, int _val)
{
    int mid = (_st + _ed) / 2;

    if (arr[mid] == _val)
        return true;

    if (_ed < _st)
        return false;

    if (arr[mid] < _val)
    {
        return binarySearch(mid + 1, _ed, _val);
    }
    else
    {
        return binarySearch(_st, mid - 1, _val);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        arr[i] = input;
    }

    sort(arr, arr + N);

    int M;
    cin >> M;

    for (size_t i = 0; i < M; i++)
    {
        int input;
        cin >> input;
        answer[i] = input;
    }

    for (size_t i = 0; i < M; i++)
    {
        cout << binarySearch(0, N - 1, answer[i]) << '\n';
    }

    return 0;
}