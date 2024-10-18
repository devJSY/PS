class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string subStr;
        std::set<char> Set;
        for (int i = 0; i < s.size();)
        {
            char ch = s[i];

            if (Set.end() == Set.find(ch))
            {
                Set.insert(ch);
                subStr += ch;

                result = max(result, (int)subStr.size());
                ++i;
            }
            else
            {
                i = 0;
                s = s.substr(1);
                subStr.clear();
                Set.clear();
            }
        }

        return result;
    }

private:
    int result = 0;
};
