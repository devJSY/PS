class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int i = 0;
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] > s[j])
            {
                ++j;
                continue;
            }

            ++result;
            ++i;
            ++j;
        }

        return result;
    }
};
