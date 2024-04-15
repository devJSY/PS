#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr[55];
bool vist[55];
int result[55];

int BFS(int _Num)
{
    std::fill(vist, vist + N + 1, false);
    queue<pair<int, int>> Q;

    vist[_Num] = true;
    Q.push(make_pair(_Num, 0));

    int result = 0;
    while (!Q.empty())
    {
        auto pair = Q.front();
        Q.pop();
        result = std::max(result, pair.second);

        for (const auto& iter : arr[pair.first])
        {
            if (vist[iter])
                continue;

            vist[iter] = true;
            Q.push(make_pair(iter, pair.second + 1));
        }

        bool bExit = true;
        for (int i = 0; i < N; i++)
        {
            if (!vist[i])
            {
                bExit = false;
                break;
            }
        }

        if (bExit)
        {
            return result;
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (1)
    {
        int u, v;
        cin >> u >> v;
        if (-1 == u && -1 == v)
            break;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        result[i] = BFS(i);
    }

    int MinNum = *min_element(result + 1, result + N + 1);
    cout << MinNum << " ";

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (result[i] == MinNum)
            cnt++;
    }

    cout << cnt << '\n';

    for (int i = 1; i <= N; i++)
    {
        if (result[i] == MinNum)
        {
            cout << i << " ";
        }
    }
    return 0;
}