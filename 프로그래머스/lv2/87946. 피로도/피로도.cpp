#include <string>
#include <vector>

using namespace std;

vector <vector<int>> temp;
int n = 0;
int answer = 0;
int ch[10] = {};

void DFS(int L, int F, int sum)
{
	if (L == temp.size())
	{
		if (answer < sum) answer = sum;
		return;
	}
	else
	{
		for (int i = 0; i < temp.size(); i++)
		{
			// 최소 필요 피로도보다 현재피로도가 큰경우
			if (temp[i][0] <= F)
			{
				if (ch[i] == 0)
				{
					ch[i] = 1;
					DFS(L + 1, F - temp[i][1], sum + 1);
					ch[i] = 0;
				}
			}
		}

		if (answer < sum) answer = sum;
	}
}

int solution(int k, vector<vector<int>> dungeons)
{
	temp = dungeons;
	n = k;

	DFS(0, n, 0);

	return answer;
}