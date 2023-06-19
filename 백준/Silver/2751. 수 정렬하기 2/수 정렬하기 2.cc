#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> vec(n);

	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}

	sort(vec.begin(), vec.end());

	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", vec[i]);
	}
	
	return 0;
}