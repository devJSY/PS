class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int st = 0;
        int ed = nums.size() - 1;

        while (st <= ed)
        {
            int mid = (st + ed) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                st = mid + 1;
            }
            else
            {
                ed = mid - 1;
            }
        }

        return -1;
    }
};