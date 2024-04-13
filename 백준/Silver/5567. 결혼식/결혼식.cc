#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr[505];
int vist[505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int result = 0;

    queue<int> Q;

    Q.push(1);
    vist[1] = 1;

    while (!Q.empty())
    {
        int Num = Q.front();
        Q.pop();

        for (int i = 0; i < arr[Num].size(); i++)
        {
            if (vist[arr[Num][i]] || vist[Num] >= 3)
                continue;

            Q.push(arr[Num][i]);
            vist[arr[Num][i]] = vist[Num] + 1;
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}