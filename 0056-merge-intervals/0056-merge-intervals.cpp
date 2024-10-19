class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        int head = intervals[0][0];
        int tail = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            // 연결이 되는 경우
            if (head <= intervals[i][0] && intervals[i][0] <= tail)
            {
                tail = max(tail, intervals[i][1]);
            }
            // 끊어지는 경우
            else
            {
                result.push_back({head, tail});

                head = intervals[i][0];
                tail = intervals[i][1];
            }
        }

        result.push_back({head, tail});

        return result;
    }
};
