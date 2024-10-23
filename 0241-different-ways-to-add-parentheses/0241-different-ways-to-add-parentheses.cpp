class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        if (expression.size() == 1)
        {
            return {expression[0] - 48};
        }
        else if (expression.size() == 2)
        {
            return {((expression[0] - 48) * 10) + (expression[1] - 48)};
        }

        vector<int> answer;
        for (int i = 0; i < expression.size(); ++i)
        {
            vector<int> Left;
            vector<int> Right;

            if (expression[i] != '*' && expression[i] != '+' && expression[i] != '-')
                continue;

            Left = diffWaysToCompute(expression.substr(0, i));
            Right = diffWaysToCompute(expression.substr(i + 1));

            if (expression[i] == '*')
            {
                for (int j = 0; j < Left.size(); ++j)
                {
                    for (int k = 0; k < Right.size(); ++k)
                    {
                        answer.push_back(Left[j] * Right[k]);
                    }
                }
            }
            else if (expression[i] == '-')
            {
                for (int j = 0; j < Left.size(); ++j)
                {
                    for (int k = 0; k < Right.size(); ++k)
                    {
                        answer.push_back(Left[j] - Right[k]);
                    }
                }
            }
            else if (expression[i] == '+')
            {
                for (int j = 0; j < Left.size(); ++j)
                {
                    for (int k = 0; k < Right.size(); ++k)
                    {
                        answer.push_back(Left[j] + Right[k]);
                    }
                }
            }
        }

        return answer;
    }
};
