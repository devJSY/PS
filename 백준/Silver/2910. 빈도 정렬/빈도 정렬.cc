#include <bits/stdc++.h>

using namespace std;

map<int, int> order;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if (a.second == b.second)
        return order[a.first] < order[b.first];

    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;

    cin >> N >> C;

    std::map<int, int> Map;

    for (size_t i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        Map[value]++;

        if (order[value] == 0)
            order[value] = i + 1;
    }

    vector<pair<int, int>> vec(Map.begin(), Map.end());

    sort(vec.begin(), vec.end(), cmp);

    for (const auto& iter : vec)
    {
        for (size_t i = 0; i < iter.second; i++)
        {
            cout << iter.first << " ";
        }
    }

    return 0;
}