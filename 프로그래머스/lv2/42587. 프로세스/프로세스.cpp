#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    location++;
	int result = 0;

	queue<int> Q;
	
	for (int i = 0; i < priorities.size(); i++)
	{
		Q.push(priorities[i]);
	}

	while (1)
	{
		int front = Q.front();
		Q.pop();
		--location;

		bool flag = false;
		for (int i = 0; i < Q.size(); i++)
		{
			if (Q.front() > front)
			{
				flag = true;
			}

			Q.push(Q.front());
			Q.pop();			
		}

		if (flag == true)
		{
			Q.push(front);		
			if (location == 0)
			{
				location = Q.size();
			}
		}
		else
		{
			result++;

			if (location == 0)
			{
				return result;
			}
		}		
	}	
}