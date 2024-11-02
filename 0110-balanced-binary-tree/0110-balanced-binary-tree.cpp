class Solution
{
public:
    int recur(TreeNode* Node)
    {
        if (!Node || !answer)
        {
            return 0;
        }

        int Left = recur(Node->left);
        int Right = recur(Node->right);

        if (abs(Left - Right) > 1)
        {
            answer = false;
        }

        return max(Left, Right) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        if (!root)
        {
            return answer;
        }

        recur(root);

        return answer;
    }

private:
    bool answer = true;
};
