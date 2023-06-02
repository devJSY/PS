#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) 
{
	priority_queue<int, vector<int>, greater<int> > pQ;

	for (int i = 0; i < scoville.size(); i++)
	{
		pQ.push(scoville[i]);
	}

	int answer = 0;

	while (1)
	{
		bool flag = false;

		if (!pQ.empty() && pQ.top() < K)
		{
			flag = true;
		}
		
		if (flag)
		{
			int one = pQ.top();
			pQ.pop();

			int two = 0;
			if (pQ.empty())
			{
                answer = -1;
				break;
			}
			else
			{
				two = pQ.top();
				pQ.pop();
			}

			pQ.push(one + (two * 2));
			answer++;
		}
		else
		{
			break;
		}
	}

	return answer;
}