class Solution
{
public:
    void dfs(int L, TreeNode* node)
    {
        if (nullptr == node)
        {
            return;
        }
        result = std::max(result, L);
        dfs(L + 1, node->left);
        dfs(L + 1, node->right);
    }

    int maxDepth(TreeNode* root)
    {
        dfs(1, root);
        return result;
    }

private:
    int result = 0;
};
