class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        set<char> Set(s.begin(), s.end());

        for (const char& ch : Set)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                if (ch != s[i])
                    continue;

                string SubString = s.substr(i);
                set<char> SubSet(SubString.begin(), SubString.end());

                if (Set == SubSet)
                {
                    SubString.erase(remove(SubString.begin(), SubString.end(), ch), SubString.end());
                    return ch + removeDuplicateLetters(SubString);
                }
            }
        }

        return string();
    }
};
