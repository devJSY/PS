bool comp(const vector<int>& A, const vector<int>& B)
{
    if (A[1] == B[1])
    {
        return A[0] > B[0];
    }

    return A[1] < B[1];
}

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), comp);
        list<vector<int>> List;

        for (int i = 0; i < people.size(); ++i)
        {
            int cnt = people[i][1];
            auto iter = List.begin();

            while (cnt)
            {
                if ((*iter)[0] >= people[i][0])
                {
                    --cnt;
                }

                ++iter;
            }

            List.insert(iter, {people[i][0], people[i][1]});
        }

        vector<vector<int>> result;
        for (const auto& elem : List)
        {
            result.push_back(elem);
        }

        return result;
    }
};
