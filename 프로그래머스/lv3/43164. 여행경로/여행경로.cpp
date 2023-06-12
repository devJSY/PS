#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string result[10001] = {};
int ch[10001] = {};
vector<string> answer;

void DFS(int L, string now, vector<vector<string>>& vec)
{
	if (L == vec.size())
	{
		if (answer.size() == 0)
		{
			result[L] = now;

			for (size_t i = 0; i < L + 1; i++)
			{
				answer.push_back(result[i]);
			}
		}

		return;
	}
	else
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (now == vec[i][0] && ch[i] == 0)
			{
				ch[i] = 1;
				result[L] = vec[i][0];
				DFS(L+1, vec[i][1], vec);
				ch[i] = 0;
			}
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) 
{
	sort(tickets.begin(), tickets.end());

	DFS(0, "ICN", tickets);
    
    return answer;
}