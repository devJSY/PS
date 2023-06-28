#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> st;
	string num;
	bool flag = true;

	while (1)
	{
		getline(cin, num);

		if (num[0] == '.') break;

		flag = true;

		for (auto ch : num)
		{
			if (ch == '(') st.push('(');
			else if (ch == '[') st.push('[');
			else if (ch == ')')
			{
				if (!st.empty() && st.top() == '(') st.pop();
				else flag = false;
			}
			else if (ch == ']')
			{
				if (!st.empty() && st.top() == '[') st.pop();
				else flag = false;
			}
		}

		if (st.empty() && flag) cout << "yes" << '\n';
		else cout << "no" << '\n';

		while (!st.empty()) st.pop();
	}

	return 0;
}