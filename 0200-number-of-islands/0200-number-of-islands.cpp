int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int M = (int)grid.size();
        int N = (int)grid[0].size();

        vector<vector<bool>> visited;
        visited.resize(M);

        for (int i = 0; i < M; ++i)
        {
            visited[i].resize(N);
        }

        int reuslt = 0;
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (grid[i][j] == '0' || visited[i][j])
                {
                    continue;
                }

                ++reuslt;
                queue<pair<int, int>> Q;
                visited[i][j] = true;
                Q.push(make_pair(i, j));

                while (!Q.empty())
                {
                    int x, y;
                    tie(x, y) = Q.front();
                    Q.pop();

                    for (int k = 0; k < 4; ++k)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[nx][ny] || grid[nx][ny] == '0')
                        {
                            continue;
                        }

                        visited[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }

        return reuslt;
    }
};
