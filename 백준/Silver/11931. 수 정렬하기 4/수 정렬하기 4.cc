#include <bits/stdc++.h>

using namespace std;

bool cmp(const int& a, const int& b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), cmp);

    for (size_t i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }

    return 0;
}