#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, string, greater<string>> map;

    int N;

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        string name, work;
        cin >> name >> work;

        map[name] = work;
    }

    for (const auto& iter : map)
    {
        if ("enter" == iter.second)
        {
            cout << iter.first << '\n';
        }
    }

    return 0;
}