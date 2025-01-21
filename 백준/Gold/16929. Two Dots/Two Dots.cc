
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>> Graph;

int N, M;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Point
{
public:
    Point(int nx, int ny)
        : x(nx)
        , y(ny)
    {
    }

    int x, y;
};

bool BFS(Point Cur, Point Parent)
{
    // Cur, Prev
    queue<tuple<Point, Point>> Q;
    Q.push(make_tuple(Cur, Point(-1, -1)));

    while (!Q.empty())
    {
        auto [Current, Prev] = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = Current.x + dx[dir];
            int ny = Current.y + dy[dir];

            // 범위를 벗어났거나 같은 문자가 아닌경우
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || Graph[Current.y][Current.x] != Graph[ny][nx])
                continue;

            // 이전 노드는 제외
            if (nx == Prev.x && ny == Prev.y)
                continue;

            // 사이클이 존재했다.
            if (Parent.x == nx && Parent.y == ny)
            {
                return true;
            }

            Q.push(make_tuple(Point(nx, ny), Current));
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Graph.resize(N, vector<int>(M));

    for (int y = 0; y < N; ++y)
    {
        string str;
        cin >> str;
        for (int x = 0; x < str.size(); ++x)
        {
            Graph[y][x] = str[x];
        }
    }

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            if (BFS(Point(x, y), Point(x, y)))
            {
                cout << "Yes" << '\n';
                exit(0);
            }
        }
    }

    cout << "No" << '\n';

    return 0;
}
