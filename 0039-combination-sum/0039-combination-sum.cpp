class Solution
{
public:
    void dfs(vector<int>& candidates, int target, vector<int> vec, int sum, int L)
    {
        if (sum >= target)
        {
            if (sum == target)
            {
                result.push_back(vec);
            }

            return;
        }

        for (int i = L; i < candidates.size(); ++i)
        {
            vector<int> temp = vec;
            temp.push_back(candidates[i]);
            dfs(candidates, target, temp, sum + candidates[i], i);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dfs(candidates, target, {}, 0, 0);
        return result;
    }

private:
    vector<vector<int>> result;
};
