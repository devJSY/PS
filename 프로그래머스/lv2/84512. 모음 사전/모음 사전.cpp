#include <string>
#include <vector>
#include <cstring>

using namespace std;

char temp[10];
char ch[10] = "AEIOU";
char res[10];
int cnt = 0;
int answer = -1;

void DFS(int L)
{
	if (strcmp(res, temp) == 0)
	{
		answer = cnt;
		return;
	}

	if (L == 5) return;

	for (int i = 0; i < 5; i++)
	{
		res[L] = ch[i];
		++cnt;
		DFS(L + 1);
		res[L] = 0;

		if (answer != -1) return;
	}

}

int solution(string word) 
{
   	int n = word.length();
	
	for (size_t i = 0; i < n; i++)
	{
		temp[i] = word[i];
	}

	DFS(0);
    
    return answer;
}