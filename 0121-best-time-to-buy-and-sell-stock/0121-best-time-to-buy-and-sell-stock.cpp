class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int Profit = 0;

        int MinValue = prices[0];
        int MaxValue = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < MinValue)
            {
                MinValue = prices[i];
                MaxValue = prices[i];
            }
            else if (prices[i] > MinValue)
            {
                MaxValue = prices[i];
                Profit = max(Profit, MaxValue - MinValue);
            }
        }

        return Profit;
    }
};
