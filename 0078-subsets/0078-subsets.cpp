class Solution
{
public:
    void dfs(vector<int>& nums, int L, vector<int> vec)
    {
        result.push_back(vec);

        for (int i = L; i < nums.size(); ++i)
        {
            if (!visted[10 + nums[i]])
            {
                visted[10 + nums[i]] = true;
                vec.push_back(nums[i]);
                dfs(nums, i, vec);
                vec.pop_back();
                visted[10 + nums[i]] = false;
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        visted.resize(100);
        dfs(nums, 0, {});
        return result;
    }

private:
    vector<vector<int>> result;
    vector<bool> visted;
};
