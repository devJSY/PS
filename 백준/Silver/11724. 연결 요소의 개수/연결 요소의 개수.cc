#include <bits/stdc++.h>

using namespace std;

vector<int> Vertex[1005];
bool vist[1005] = {};
int N, M;

int BFS()
{
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (vist[i])
            continue;

        queue<int> Q;
        Q.push(i);
        vist[i] = true;
        result++;

        while (!Q.empty())
        {
            int Num = Q.front();
            Q.pop();

            for (const auto& iter : Vertex[Num])
            {
                if (vist[iter])
                    continue;

                Q.push(iter);
                vist[iter] = true;
            }
        }
    }

    return result;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        Vertex[u].push_back(v);
        Vertex[v].push_back(u);
    }

    cout << BFS() << '\n';

    return 0;
}