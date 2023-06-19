#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string& a, string& b)
{
	if (a == b) return false;
	if (a.length() == b.length())
	{
		for (size_t i = 0; i < min(a.length(), b.length()); i++)
		{
			if(a[i] == b[i]) continue;

			if (a[i] < b[i]) return true;
			else return false;
		}		
	}
	else
	{
		return a.length() < b.length();
	}
}

int main()
{
	int n = 0;
	cin >> n;

	vector<string> vec(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end(), cmp);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());


	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}


	return 0;
}