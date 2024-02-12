#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr;

        for (size_t i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        long long result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                result += gcd(arr[i], arr[j]);
            }
        }

        cout << result << '\n';
    }

    return 0;
}