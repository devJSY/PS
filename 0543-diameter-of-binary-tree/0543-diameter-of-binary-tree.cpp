class Solution
{
public:
    void re_dfs(TreeNode* Node)
    {
        if (!Node)
            return;

        result = std::max(result, dfs(0, Node->left) + dfs(0, Node->right));
        re_dfs(Node->left);
        re_dfs(Node->right);
    }

    int dfs(int L, TreeNode* Node)
    {
        // 리프노드인경우 현재 레벨을 리턴
        if (!Node)
        {
            return L;
        }

        return std::max(dfs(L + 1, Node->left), dfs(L + 1, Node->right));
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        re_dfs(root);

        return result;
    }

private:
    int result = 0;
};
