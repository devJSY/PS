class Solution
{
public:
    int trap(vector<int>& height)
    {
        int answer = 0;

        // 제일 큰 값 탐색
        int MaxValIdx = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            if (height[MaxValIdx] <= height[i])
            {
                MaxValIdx = i;
            }
        }

        // Left
        {
            stack<int> st; // idx
            int Lp = 0;
            int CurNum = height[Lp];

            // 제일 큰값 기준 왼쪽 탐색
            while (Lp <= MaxValIdx)
            {
                if (height[Lp] <= CurNum)
                {
                    st.push(Lp);
                }
                else
                {
                    while (!st.empty())
                    {
                        answer += CurNum - height[st.top()];
                        st.pop();
                    }

                    st.push(Lp);
                    CurNum = height[Lp];
                }

                ++Lp;
            }

            while (!st.empty())
            {
                answer += CurNum - height[st.top()];
                st.pop();
            }
        }

        // right
        {
            stack<int> st; // idx
            int Rp = height.size() - 1;
            int CurNum = height[Rp];

            // 제일 큰값 기준 왼쪽 탐색
            while (Rp >= MaxValIdx)
            {
                if (height[Rp] <= CurNum)
                {
                    st.push(Rp);
                }
                else
                {
                    while (!st.empty())
                    {
                        answer += CurNum - height[st.top()];
                        st.pop();
                    }

                    st.push(Rp);
                    CurNum = height[Rp];
                }

                --Rp;
            }

            while (!st.empty())
            {
                answer += CurNum - height[st.top()];
                st.pop();
            }
        }

        return answer;
    }
};
