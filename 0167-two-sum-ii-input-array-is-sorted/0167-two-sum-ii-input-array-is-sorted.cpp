class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int Lp = 0;
        int Rp = numbers.size() - 1;

        while (Lp <= Rp)
        {
            if (numbers[Lp] + numbers[Rp] > target)
            {
                --Rp;
            }
            else if (numbers[Lp] + numbers[Rp] < target)
            {
                ++Lp;
            }
            else
            {
                return {Lp + 1, Rp + 1};
            }
        }

        return {};
    }
};
