#include <iostream>
#include <deque>

using namespace std;

int DequeFront(deque<int> dq, int num)
{
	int cnt = 0;

	while (1)
	{
		int front = dq.front();
		if (front == num) break;

		dq.pop_front();
		dq.push_back(front);
		cnt++;
	}

	return cnt;
}

int Dequeback(deque<int> dq, int num)
{
	int cnt = 0;

	while (1)
	{
		int back = dq.back();
		if (back == num) break;

		dq.pop_back();
		dq.push_front(back);
		cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;

	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	int m = 0;
	cin >> m;

	int result = 0;

	for (size_t i = 0; i < m; i++)
	{
		int num = 0;
		cin >> num;

		int a = DequeFront(dq, num);
		int b = Dequeback(dq, num);

		if (a > b)
		{
			while (1)
			{
				int back = dq.back();
				if (back == num)
				{
					dq.pop_back();
					break;
				}

				dq.pop_back();
				dq.push_front(back);
			}

			result += b;
			result += 1;
		}
		else
		{
			while (1)
			{
				int front = dq.front();
				if (front == num)
				{			
					dq.pop_front();
					break;
				}

				dq.pop_front();
				dq.push_back(front);
			}

			result += a;
		}
	}

	cout << result;

	return 0;
}