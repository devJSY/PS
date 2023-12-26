#include <bits/stdc++.h>

std::string arr[50] = {};

using namespace std;

bool cmp(const string& a, const string& b)
{
    if (a.length() == b.length())
    {
        int aSum = 0;

        for (auto ch : a)
        {
            if (ch >= '0' && ch <= '9')
                aSum += (ch - '0');
        }

        int bSum = 0;

        for (char ch : b)
        {
            if (ch >= '0' && ch <= '9')
                bSum += (ch - '0');
        }

        if (aSum == bSum)
        {
            return a < b;
        }
        else
        {
            return aSum < bSum;
        }
    }
    else
    {
        return a.length() < b.length();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N, cmp);

    for (size_t i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }

    return 0;
}