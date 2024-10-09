class Solution
{
public:
    void dfs(int L, int num, vector<int> str)
    {
        if (L == K)
        {
            result.push_back(str);
            return;
        }

        for (int i = num + 1; i <= N; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                str.push_back(i);
                dfs(L + 1, i, str);
                str.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        N = n;
        K = k;

        visited.resize(50);

        for (int i = 1; i <= N; ++i)
        {
            visited[i] = true;
            dfs(1, i, {i});
        }

        return result;
    }

private:
    vector<vector<int>> result;
    vector<bool> visited;
    int N;
    int K;
};
