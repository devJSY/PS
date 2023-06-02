#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;

	for (size_t i = 0; i < prices.size() - 1; i++)
	{
		int term = 0;
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (prices[i] > prices[j])
			{
				term++;
				break;
			}
			else
			{
				term++;
			}
		}

		answer.push_back(term);
	}

	answer.push_back(0);
    
    return answer;
}