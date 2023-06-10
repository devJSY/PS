#include <string>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& vec, int n, int L)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (vec[L][i] == 1)
		{
			flag = true;
			vec[L][i] = 0;
			vec[i][L] = 0;
			DFS(vec, n, i);
		}
	}

	return flag;
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (DFS(computers, n, i) == true)
		{
			answer++;
		}
	}

    return answer;
}