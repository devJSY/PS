class Solution
{
public:
    void dfs(vector<int>& nums, int L, vector<int> vec)
    {
        result.push_back(vec);

        for (int i = L; i < nums.size(); ++i)
        {
            vec.push_back(nums[i]);
            dfs(nums, i + 1, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(nums, 0, {});
        return result;
    }

private:
    vector<vector<int>> result;
};
