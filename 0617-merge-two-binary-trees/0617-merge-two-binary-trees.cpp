class Solution
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        TreeNode* NewNode = nullptr;

        if (root1 && root2)
        {
            NewNode = new TreeNode(root1->val + root2->val);
        }
        else if (root1)
        {
            NewNode = new TreeNode(root1->val);
        }
        else if (root2)
        {
            NewNode = new TreeNode(root2->val);
        }
        else
        {
            return nullptr;
        }

        NewNode->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        NewNode->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);

        return NewNode;
    }
};
