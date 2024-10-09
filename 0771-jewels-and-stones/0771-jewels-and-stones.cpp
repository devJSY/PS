class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        vector<int> arr(200);

        for (const char& c : stones)
        {
            ++arr[c];
        }

        int result = 0;

        for (const char& c : jewels)
        {
            result += arr[c];
        }

        return result;
    }
};
