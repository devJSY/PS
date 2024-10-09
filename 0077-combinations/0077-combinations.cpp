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
            str.push_back(i);
            dfs(L + 1, i, str);
            str.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        N = n;
        K = k;

        for (int i = 1; i <= N; ++i)
        {
            dfs(1, i, {i});
        }

        return result;
    }

private:
    vector<vector<int>> result;
    int N;
    int K;
};
