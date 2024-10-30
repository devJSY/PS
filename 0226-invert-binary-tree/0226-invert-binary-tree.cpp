class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root)
        {
            return root;
        }

        TreeNode* Left = root->left;
        TreeNode* Right = root->right;

        root->right = Left;
        root->left = Right;

        invertTree(Left);
        invertTree(Right);

        return root;
    }
};
