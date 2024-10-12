class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        std::set<int> Set;

        // 중복제거
        for (int i = 0; i < nums1.size(); ++i)
        {
            Set.insert(nums1[i]);
        }

        // nums1 집합에 포함되어있는지 탐색 
        std::set<int> ResultSet;
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (Set.find(nums2[i]) != Set.end())
            {
                ResultSet.insert(nums2[i]);
            }
        }
        
        vector<int> result;
        for (const int& elem : ResultSet)
        {
            result.push_back(elem);
        }

        return result;
    }
};
