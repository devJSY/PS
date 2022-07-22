#include <vector>
long long sum(std::vector<int>& a) {
	int i;
	long long ans = 0;
	for (i = 0; i < a.size(); ++i)
	{
		ans += a[i];
	}
	
	return ans;
}