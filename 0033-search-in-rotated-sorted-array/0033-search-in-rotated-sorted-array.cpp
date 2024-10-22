class Solution
{
public:
    int BinarySearch(vector<int>& nums, int Left, int Right, int K, int Target)
    {
        if (Left > Right)
        {
            return -1;
        }

        int Mid = (Left + Right) / 2;
        int KMid = (Mid + K) % nums.size();
        if (nums[KMid] > Target)
        {
            return BinarySearch(nums, Left, Mid - 1, K, Target);
        }
        else if (nums[KMid] < Target)
        {
            return BinarySearch(nums, Mid + 1, Right, K, Target);
        }

        return KMid;
    }

    int FindK(vector<int>& nums, int Left, int Right)
    {
        int Mid = (Left + Right) / 2;

        // 0인덱스 예외처리
        if (0 == Mid)
        {
            if (nums[Mid] < nums[nums.size() - 1])
            {
                return Mid;
            }
        }
        else
        {
            if (nums[Mid] < nums[Mid - 1])
            {
                return Mid;
            }
        }

        if (Left >= Right)
        {
            return 0;
        }

        return max(FindK(nums, Left, Mid - 1), FindK(nums, Mid + 1, Right));
    }

    int search(vector<int>& nums, int target)
    {
        int K = FindK(nums, 0, nums.size() - 1);
        int result = BinarySearch(nums, 0, nums.size(), K, target);
        return result;
    }
};
