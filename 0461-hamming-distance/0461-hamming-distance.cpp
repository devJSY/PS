class Solution
{
public:
    int hammingDistance(int x, int y) 
    { 
        int result = 0;
        for (int i = 0; i < 32; ++i)
        {
            bool a = x & (1 << i);
            bool b = y & (1 << i);
            if (a != b)
            {
                ++result;
            }
        }

        return result;
    }
};
