#include<vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    if (maps.empty()) return 1;

	int n = maps.size();
	int m = maps[0].size();

	queue <pair<int, int>> Q;
	int direct[4][2] =
	{
		{0,1},
		{0,-1},
		{1,0},
		{-1,0}
	};

	Q.push(make_pair(0, 0));
	maps[0][0] = 1;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int newY = y + direct[i][0];
			int newX = x + direct[i][1];

			if (newY >= 0 && newY < n &&
				newX >= 0 && newX < m &&
				maps[newY][newX] == 1)
			{
				maps[newY][newX] = maps[y][x] + 1;
				Q.push(make_pair(newY, newX));
			}
		}

		Q.pop();
	}

	if (maps[n - 1][m - 1] > 1) return maps[n - 1][m - 1];
	return -1;
}