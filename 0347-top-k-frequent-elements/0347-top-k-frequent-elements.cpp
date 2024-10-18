class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> Map;
        for (int i = 0; i < nums.size(); ++i)
        {
            Map[nums[i]]++;
        }

        priority_queue<pair<int, int>> pQ;

        for (auto& elem : Map)
        {
            pQ.push(make_pair(elem.second, elem.first));
        }

        vector<int> result;

        while (k--)
        {
            result.push_back(pQ.top().second);
            pQ.pop();
        }

        return result;
    }
};
