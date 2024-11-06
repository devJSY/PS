class Solution
{
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if (!root)
        {
            return 0;
        }

        int answer = 0;
        if (root->val >= low && root->val <= high)
        {
            answer += root->val;
        }
        answer += rangeSumBST(root->left, low, high);
        answer += rangeSumBST(root->right, low, high);

        return answer;
    }
};
