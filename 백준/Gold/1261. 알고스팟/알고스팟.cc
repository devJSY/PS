#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

const int INF = 987654321;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;

vector<vector<int>> Graph;
vector<vector<int>> Weight;

void solve()
{
    // 뚫어야하는 벽의 갯수, x, y
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pQ;
    pQ.push(make_tuple(0, 0, 0));
    Weight[0][0] = 0;

    while (!pQ.empty())
    {
        auto [cnt, x, y] = pQ.top();
        pQ.pop();

        if (x == M - 1 && y == N - 1)
        {
            cout << cnt << '\n';
            break;
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 범위 밖을 벗어나는 경우
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;

            int NextCnt = cnt;
            if (Graph[ny][nx] == '1')
            {
                ++NextCnt;
            }

            if (Weight[ny][nx] > NextCnt)
            {
                Weight[ny][nx] = NextCnt;
                pQ.push(make_tuple(NextCnt, nx, ny));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    Graph.resize(N, vector<int>(M));
    Weight.resize(N, vector<int>(M, INF));

    string str;
    for (int y = 0; y < N; ++y)
    {
        cin >> str;

        for (int x = 0; x < str.size(); ++x)
        {
            Graph[y][x] = str[x];
        }
    }

    solve();

    return 0;
}
