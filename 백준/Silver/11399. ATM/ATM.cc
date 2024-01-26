#include <bits/stdc++.h>

using namespace std;

int arr[1005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int result = 0;
    int acc = 0;

    for (size_t i = 0; i < N; i++)
    {
        result += acc + arr[i];
        acc += arr[i];
    }

    cout << result;

    return 0;
}
