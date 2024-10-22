class Solution
{
public:
    void RecurFindPos(TreeNode* ParentNode, int Value)
    {
        int ParentNodeIdx = uomap[ParentNode->val];
        int Idx = uomap[Value];

        if (Idx < ParentNodeIdx)
        {
            if (ParentNode->left)
            {
                RecurFindPos(ParentNode->left, Value);
            }
            else
            {
                ParentNode->left = new TreeNode;
                ParentNode->left->val = Value;
            }
        }
        else
        {
            if (ParentNode->right)
            {
                RecurFindPos(ParentNode->right, Value);
            }
            else
            {
                ParentNode->right = new TreeNode;
                ParentNode->right->val = Value;
            }
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            uomap[inorder[i]] = i;
        }

        TreeNode* RootNode = new TreeNode;
        RootNode->val = preorder[0];

        for (int i = 1; i < preorder.size(); ++i)
        {
            RecurFindPos(RootNode, preorder[i]);
        }

        return RootNode;
    }

private:
    // Value, Index
    unordered_map<int, int> uomap;
};
