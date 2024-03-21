#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> Map;

    int K, L;

    cin >> K >> L;

    for (size_t i = 0; i < L; i++)
    {
        string Num;
        cin >> Num;
        Map[Num] = i;
    }

    std::vector<pair<string, int>> vec(Map.begin(), Map.end());
    sort(vec.begin(), vec.end(), cmp);

    int LoopCnt = std::min(K, (int)vec.size());

    for (size_t i = 0; i < LoopCnt; i++)
    {
        cout << vec[i].first << '\n';
    }

    return 0;
}