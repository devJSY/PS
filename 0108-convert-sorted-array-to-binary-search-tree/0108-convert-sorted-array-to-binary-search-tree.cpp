class Solution
{
public:
    TreeNode* BinarySearch(vector<int>& nums, int Left, int Right)
    {
        if (Left > Right)
        {
            return nullptr;
        }

        int mid = (Left + Right) / 2;
        TreeNode* ParentNode = new TreeNode;
        ParentNode->val = nums[mid];

        ParentNode->left = BinarySearch(nums, Left, mid - 1);
        ParentNode->right = BinarySearch(nums, mid + 1, Right);

        return ParentNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    { 
        return BinarySearch(nums, 0, nums.size() - 1); 
    }
};
