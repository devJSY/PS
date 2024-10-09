vector<vector<char>> number = {
    {},
    {},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'},
};

class Solution
{
public:
    void dfs(int L, string str, string digits, vector<string>& result)
    {
        if (L == digits.size())
        {
            result.push_back(str);
            return;
        }

        for (char ch : number[digits[L] - '0'])
        {
            dfs(L + 1, str + ch, digits, result);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
            return result;

        dfs(0, "", digits, result);
        return result;
    }
};
