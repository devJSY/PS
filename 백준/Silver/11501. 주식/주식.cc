#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        long long result = 0;

        int N;
        cin >> N;

        vector<int> vec(N);
        for (size_t i = 0; i < N; i++)
        {
            cin >> vec[i];
        }

        int MaxNum = 0;

        for (int i = N - 1; i >= 0; i--)
        {
            if (MaxNum < vec[i])
            {
                MaxNum = vec[i];
            }
            else
            {
                result += MaxNum - vec[i];
            }
        }

        cout << result << '\n';
    }

    return 0;
}