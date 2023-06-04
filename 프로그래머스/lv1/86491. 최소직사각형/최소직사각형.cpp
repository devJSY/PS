#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
	vector<int> arr1;
	vector<int> arr2;

	for (size_t i = 0; i < sizes.size(); i++)
	{
		if (sizes[i][0] > sizes[i][1])
		{
			arr1.push_back(sizes[i][0]);
			arr2.push_back(sizes[i][1]);
		}
		else
		{
			arr1.push_back(sizes[i][1]);
			arr2.push_back(sizes[i][0]);
		}
	}

	return (*max_element(arr1.begin(), arr1.end())) * (*max_element(arr2.begin(), arr2.end()));

}