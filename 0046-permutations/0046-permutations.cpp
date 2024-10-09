class Solution
{
public:
    void dfs(int L, vector<int>& nums, vector<int> arr)
    {
        if (L == nums.size())
        {
            result.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                arr.push_back(nums[i]);
                dfs(L + 1, nums, arr);
                arr.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        dfs(0, nums, {});

        return result;
    }

private:
    bool visited[10];
    vector<vector<int>> result;
};
