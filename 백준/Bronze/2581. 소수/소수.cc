#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	int m = 0;

	cin >> m >> n;

	vector<int> vec(10001, -1);

	vec[0] = 1;
	vec[1] = 1;

	for (int i = 2; i < sqrt(n); i++)
	{
		if (vec[i] == -1)
		{
			for (int j = i + i; j <= n; j += i)
			{
				vec[j] = 1;
			}
		}
	}

	int sum = 0;
	int min = -1;
	bool minflag = false;

	for (int i = m; i <= n; i++)
	{
		if (vec[i] == -1)
		{
			if (minflag == false)
			{
				min = i;
				minflag = true;
			}
			
			sum += i;
		}		
	}

	if (min == -1) cout << -1 << endl;
	else
	{
		cout << sum << endl;
		cout << min << endl;
	}


    return 0;
}
