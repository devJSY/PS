#include <string>
#include <vector>

using namespace std;
int answer = 0;
int ch[100] = {};

void DFS(vector<string> words, string begin, string target, int cnt)
{
	if (begin == target)
	{
		if (answer > 0) return;
		else
		{
			answer = cnt;
		}		
		return;
	}
	else
	{
		// 먼저 확인
		int SameCnt = 0;
		for (int j = 0; j < begin.size(); j++)
		{
			if (begin[j] != target[j])  SameCnt++;
		}

		if (SameCnt < 2)
		{
			if (answer > 0) return;
			answer = cnt + 1;
			return;
		}

		for (int i = 0; i < words.size(); i++)
		{
			int SameCnt = 0;
			for (int j = 0; j < begin.size(); j++)
			{
				if (begin[j] != words[i][j]) SameCnt++;
			}

			if (SameCnt < 2 && ch[i] == 0)
			{
				ch[i] = 1;
				DFS(words, words[i], target, cnt + 1);
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) 
{
	bool flag = false;
	for (size_t i = 0; i < words.size(); i++)
	{
		if (words[i] == target) flag = true;
	}

	if (flag)
	{
		DFS(words, begin, target, 0);
	}
	else
	{
		return 0;
	}

	return answer;
}