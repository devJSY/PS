#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0, temp, cnt = 0;

	cin >> n;

	while (cnt != n)
	{
		ans++;
		temp = ans;

		while (temp !=0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else temp /= 10;
		}
	}

	cout << ans << endl;

	return 0;
}
