class Solution
{
public:
    void sortColors(vector<int>& nums) 
    { 
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] < nums[i])
                {
                    std::swap(nums[j], nums[i]);
                }
            }
        }
    }
};
