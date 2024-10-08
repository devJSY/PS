class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
        MaxSize = k;
        CircularQ.resize(MaxSize, -1);
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }

        CircularQ[BackIdx] = value;
        ++BackIdx;

        if (BackIdx == MaxSize)
        {
            BackIdx = 0;
        }

        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        CircularQ[FrontIdx] = -1;
        ++FrontIdx;

        if (FrontIdx == MaxSize)
        {
            FrontIdx = 0;
        }

        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }

        return CircularQ[FrontIdx];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return 0 == BackIdx ? CircularQ[MaxSize - 1] : CircularQ[BackIdx - 1];
    }

    bool isEmpty() { return FrontIdx == BackIdx && CircularQ[FrontIdx] == -1; }

    bool isFull() { return FrontIdx == BackIdx && CircularQ[FrontIdx] != -1; }

private:
    vector<int> CircularQ;
    int MaxSize = 0;
    int FrontIdx = 0;
    int BackIdx = 0;
};
