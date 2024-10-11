bool comp(const pair<int, int>& A, const pair<int, int>& B)
{
    return A.first < B.first;
}

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<pair<int, int>> DistVec; // 거리, points에서의 인덱스

        for (int i = 0; i < points.size(); ++i)
        {
            DistVec.push_back(make_pair((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]), i));
        }

        // 거리값 기준으로 정렬
        sort(DistVec.begin(), DistVec.end(), comp);

        // 정답 추출
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i)
        {
            result.push_back(points[DistVec[i].second]);
        }

        return result;
    }
};
