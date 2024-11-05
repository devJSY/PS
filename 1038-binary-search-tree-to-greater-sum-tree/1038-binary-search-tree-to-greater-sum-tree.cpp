class Solution
{
public:
    void dfs(TreeNode* Node, int& SumVal)
    {
        if (!Node)
        {
            return;
        }

        if (!Node->right)
        {
            if (0 == SumVal)
            {
                SumVal = Node->val;
            }
        }
        else
        {
            dfs(Node->right, SumVal);
        }

        if (SumVal != Node->val)
        {
            Node->val += SumVal;
        }
        SumVal = Node->val;

        if (Node->left)
        {
            dfs(Node->left, SumVal);
        }
    }

    TreeNode* bstToGst(TreeNode* root)
    {
        int val = 0;
        dfs(root, val);
        return root;
    }
};
