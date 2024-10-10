class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        adjList.resize(n + 1);
        table.resize(n + 1);

        // 테이블 값 초기화
        std::fill(table.begin(), table.end(), 2147000000);

        // 인접리스트 생성
        for (int i = 0; i < times.size(); ++i)
        {
            adjList[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }

        // w, u, v
        // 최대 힙 선언
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;

        for (int i = 0; i < adjList[k].size(); ++i)
        {
            int v, w;
            tie(v, w) = adjList[k][i];

            Q.push(make_tuple(w, k, v));
        }

        table[k] = 0;

        while (!Q.empty())
        {
            int w, u, v;
            tie(w, u, v) = Q.top();
            Q.pop();

            // 현재 노드에서 다음노드로 이동하는 비용이 기존 테이블 비용보다 비싸면 진행 X
            if (table[u] + w > table[v])
            {
                continue;
            }

            table[v] = w;

            for (int i = 0; i < adjList[v].size(); ++i)
            {
                int nv, nw;
                tie(nv, nw) = adjList[v][i];

                Q.push(make_tuple(table[v] + nw, v, nv));
            }
        }

        int result = 0;
        for (int i = 1; i < table.size(); ++i)
        {
            result = std::max(result, table[i]);
            if (table[i] == 2147000000)
            {
                return -1;
            }
        }

        return result;
    }

private:
    vector<vector<pair<int, int>>> adjList; // u, v, w
    vector<int> table;
};
