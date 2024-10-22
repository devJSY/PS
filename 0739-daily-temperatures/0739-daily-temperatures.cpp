class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> Daily(temperatures.size());

        stack<int> st;

        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                Daily[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return Daily;
    }
};
