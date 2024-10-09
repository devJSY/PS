class Solution
{
public:
    bool dfs(int Num, int TargetNum)
    {
        if (Num == TargetNum)
        {
            return false;
        }

        for (int N : Table[Num])
        {
            if (!visited[N])
            {
                visited[N] = true;
                if (!dfs(N, TargetNum))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        Table.resize(numCourses);
        visited.resize(numCourses);

        for (vector<int>& it : prerequisites)
        {
            std::fill(visited.begin(), visited.end(), false);
            visited[it[0]] = true;
            if (!dfs(it[0], it[1]))
            {
                return false;
            }
            Table[it[1]].push_back(it[0]);
        }

        return true;
    }

private:
    vector<vector<int>> Table;
    vector<bool> visited;
};
