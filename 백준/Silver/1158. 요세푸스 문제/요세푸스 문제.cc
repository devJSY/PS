#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> List;
    vector<int> result;

    int n, k;
    cin >> n >> k;

    for (size_t i = 1; i <= n; i++)
    {
        List.push_back(i);
    }

    auto iter = List.begin();
    int temp = k;

    while (!List.empty())
    {
        while (temp - 1 > 0)
        {
            iter++;
            if (iter == List.end())
                iter = List.begin();
            --temp;
        }

        result.push_back(*iter);
        iter = List.erase(iter);
        if (iter == List.end())
            iter = List.begin();
        temp = k;
    }

    cout << '<';
    for (size_t i = 0; i < result.size() - 1; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[result.size() - 1];
    cout << '>';

    return 0;
}
