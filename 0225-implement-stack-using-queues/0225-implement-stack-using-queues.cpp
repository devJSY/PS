class MyStack
{
public:
    MyStack() {}

    void push(int x) { Q.push_back(x); }

    int pop()
    {
        int PopNum = Q.back();
        Q.pop_back();
        return PopNum;
    }

    int top() { return Q.back(); }

    bool empty() { return Q.empty(); }

    private:
    std::deque<int> Q;
};
