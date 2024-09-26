class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> Map;

		for (int i = 0; i < nums.size(); ++i)
		{
			// Map 에 target - nums[i] 값이 있는지 체크
			auto it = Map.find(target - nums[i]);

			if (Map.end() != it && i != it->second)
			{
				return { i, it->second };
			}

			// 키와 인덱스를 바뀌어서 저장
			Map.insert(make_pair(nums[i], i));
		}

		return {};
	}
};
