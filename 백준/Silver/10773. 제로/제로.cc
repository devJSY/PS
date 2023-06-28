#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	stack<int> st;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num = 0;

		cin >> num;

		if (num == 0) st.pop();
		else st.push(num);
	}

	int result = 0;

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}
	
	cout << result << '\n';

	return 0;
}