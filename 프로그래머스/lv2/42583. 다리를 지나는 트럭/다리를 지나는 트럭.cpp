#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
   	queue<int> Q;
	queue<pair<int,int>> waitQ;
	int answer = 0;

	for (int i = 0; i < truck_weights.size(); i++)
	{
		Q.push(truck_weights[i]);
	}


	while (1)
	{
		while (1)
		{
			if (!waitQ.empty() && waitQ.front().second > bridge_length)
			{
				weight += waitQ.front().first;
				waitQ.pop();
			}
			else
			{
				break;
			}
		}

		if (!Q.empty() && weight - Q.front() >= 0)
		{
			waitQ.push(make_pair(Q.front(), 1));
			weight -= Q.front();
			Q.pop();
		}

		for (size_t i = 0; i < waitQ.size(); i++)
		{
			waitQ.push(make_pair(waitQ.front().first, waitQ.front().second + 1));
			waitQ.pop();
		}

		answer++;

		if (Q.empty() && waitQ.empty()) break;
	}

	return answer;	
}