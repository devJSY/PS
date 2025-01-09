#include <iostream>
#include <algorithm>

using namespace std;

int arr[500];
int DP[500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    DP[0] = arr[0];
    DP[1] = arr[0] + arr[1];
    DP[2] = arr[2] + max(arr[0], arr[1]);

    for (int i = 3; i < N; ++i)
    {
        DP[i] = arr[i] + max(DP[i - 3] + arr[i - 1], DP[i - 2]);
    }

    cout << DP[N - 1] << '\n';

    return 0;
}