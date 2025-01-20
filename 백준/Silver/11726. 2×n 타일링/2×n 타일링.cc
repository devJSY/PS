#include <iostream>

using namespace std;

int DP[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= 1000; ++i)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
    }

    int n;
    cin >> n;
    cout << DP[n];

    return 0;
}
