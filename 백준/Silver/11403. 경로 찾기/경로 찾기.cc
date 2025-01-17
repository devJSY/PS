#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> adj[105];
vector<bool> visited;
vector<vector<int>> result;

void DFS(int start, int idx)
{
    for (const int& next : adj[idx])
    {
        if (!visited[next])
        {
            visited[next] = true;
            result[start][next] = 1;
            DFS(start, next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N);
    result.resize(N, vector<int>(N, 0));

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            int num;
            cin >> num;
            if (num)
            {
                adj[y].push_back(x);
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        std::fill(visited.begin(), visited.end(), false);
        DFS(i, i);
    }

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cout << result[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}