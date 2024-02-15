#include <bits/stdc++.h>

using namespace std;

int arr[1000005] = {};
int sortedArr[1000005] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
        sortedArr[i] = arr[i];
    }

    sort(sortedArr, sortedArr + N);

    vector<int> vec;

    for (size_t i = 0; i < N - 1; i++)
    {
        if (sortedArr[i] != sortedArr[i + 1])
        {
            vec.push_back(sortedArr[i]);
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();

        cout << idx << " ";
    }

    return 0;
}