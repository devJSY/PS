class Solution
{
public:
    void dfs(TreeNode* Node, vector<int>& vec)
    {
        if (!Node)
            return;

        dfs(Node->left, vec);
        vec.push_back(Node->val);
        dfs(Node->right, vec);
    }

    int minDiffInBST(TreeNode* root)
    {
        vector<int> vec;
        dfs(root, vec);

        int answer = 2147000000;
        for (int i = 1; i < vec.size(); ++i)
        {
            answer = min(answer, vec[i] - vec[i - 1]);
        }

        return answer;
    }
};
