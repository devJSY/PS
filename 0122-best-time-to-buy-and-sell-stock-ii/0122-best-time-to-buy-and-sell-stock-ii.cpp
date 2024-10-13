class Solution
{
public:
    int maxProfit(vector<int>& prices) 
    { 
        int Profit = 0;
        int minValue = 2147000000;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < minValue)
            {
                minValue = prices[i];
            }

            if (minValue < prices[i])
            {
                Profit += prices[i] - minValue;
                minValue = prices[i];
            }
        }
        
        return Profit;
    }
};
