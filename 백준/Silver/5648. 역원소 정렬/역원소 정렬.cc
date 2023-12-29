#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> arr(N);

    for (size_t i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        arr[i] = stoll(str);
    }

    sort(arr.begin(), arr.end());

    for (size_t i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }


    return 0;
}