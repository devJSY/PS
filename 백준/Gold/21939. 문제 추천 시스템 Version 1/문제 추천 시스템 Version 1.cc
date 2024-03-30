#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> Set;
map<int, int> Map;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        int P, L;
        cin >> P >> L;
        Set.insert({L, P});
        Map[P] = L;
    }

    int M;
    cin >> M;

    for (size_t i = 0; i < M; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "recommend")
        {
            int x;
            cin >> x;

            if (1 == x)
                cout << prev(Set.end())->second << '\n';
            else if (-1 == x)
                cout << Set.begin()->second << '\n';
        }
        else if (cmd == "add")
        {
            int P, L;
            cin >> P >> L;
            Set.insert({L, P});
            Map[P] = L;
        }
        else if (cmd == "solved")
        {
            int P;
            cin >> P;
            Set.erase({Map[P], P});
            Map.erase(P);
        }
    }

    return 0;
}