#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<string> Set;

	string str;
	cin >> str;
	
	for (size_t i = 0; i < str.size(); i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			Set.insert(str.substr(j, str.size() - i));
		}
	}

	cout << Set.size() << '\n';


	return 0;
}