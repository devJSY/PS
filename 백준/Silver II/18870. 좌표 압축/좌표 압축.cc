#include <bits/stdc++.h>

using namespace std;

int arr[1000005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> vec;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
        vec.push_back(arr[i]);
    }

    sort(vec.begin(), vec.end());

    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (size_t i = 0; i < N; i++)
        cout << lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin() << " ";

    return 0;
}