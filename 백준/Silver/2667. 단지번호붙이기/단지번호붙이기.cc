#include <bits/stdc++.h>

using namespace std;

int N;
int arr[30][30];
bool vist[30][30];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int _y, int _x)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(_y, _x));
    vist[_y][_x] = 1;
    int cnt = 1;

    while (!Q.empty())
    {
        int y, x;
        tie(y, x) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;

            if (vist[ny][nx] || 0 == arr[ny][nx])
                continue;

            Q.push(make_pair(ny, nx));
            vist[ny][nx] = 1;
            ++cnt;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); ++j)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    vector<int> result;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (vist[y][x] || 0 == arr[y][x])
                continue;

            result.push_back(BFS(y, x));
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int Num : result)
    {
        cout << Num << '\n';
    }

    return 0;
}
