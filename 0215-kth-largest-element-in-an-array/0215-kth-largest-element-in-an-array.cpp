
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> Q;

        for (int i = 0; i < nums.size(); ++i)
        {
            Q.push(nums[i]);
        }

        while (--k)
        {
            Q.pop();
        }

        return Q.top();
    }
};
