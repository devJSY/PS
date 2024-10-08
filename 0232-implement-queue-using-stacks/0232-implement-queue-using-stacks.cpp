class MyQueue
{
public:
    MyQueue() {}

    void push(int x)
    {
        if (bStChanged)
            SwapStack();

        st1.push(x);
    }

    int pop()
    {
        if (!bStChanged)
            SwapStack();

        int PopNum = st2.top();
        st2.pop();
        return PopNum;
    }

    int peek()
    {
        if (!bStChanged)
            SwapStack();

        return st2.top();
    }

    bool empty() { return bStChanged ? st2.empty() : st1.empty(); }

private:
    void SwapStack()
    {
        // st1 → st2
        if (bStChanged)
        {
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        // st2 → st1
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        bStChanged = !bStChanged;
    }

private:
    stack<int> st1;
    stack<int> st2;
    bool bStChanged = false;
};
