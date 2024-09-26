class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int len = (int)nums.size();
        vector<int> result(len);

        // 오른쪽 곱 계산
        int p = 1;
        for (int i = 0; i < len; ++i)
        {
            result[i] = p;
            p *= nums[i]; 
        }

        // 왼쪽 곱계산 
        // 오른쪽 곱 값과 곱하여 최종 값 결정
        p = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            result[i] *= p;
            p *= nums[i];
        }

        return result;
    }
};
