#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    queue<pair<int, int>> Q;
	vector<int> answer;

	for (int i = 0; i < progresses.size(); i++)
	{
		Q.push(make_pair(progresses[i], speeds[i]));
	}

	while (!Q.empty())
	{
		for (int i = 0; i < Q.size(); i++)
		{
			Q.push(make_pair(Q.front().first + Q.front().second, Q.front().second));
			Q.pop();
		}

		int cnt = 0;

		while (!Q.empty() && Q.front().first >= 100)
		{
			Q.pop();
			cnt++;
		}

		if (cnt > 0) answer.push_back(cnt);
	}
    
    return answer;
}