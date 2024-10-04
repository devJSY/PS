class Solution
{
public:
    ListNode* recurSwap(ListNode* Node)
    {
        if (nullptr == Node)
            return nullptr;

        if (nullptr == Node->next)
            return Node;

        ListNode* NextNode = Node->next;

        Node->next = recurSwap(NextNode->next);
        NextNode->next = Node;

        return NextNode;
    }

    ListNode* swapPairs(ListNode* head)
    {
        ListNode* ResultHead = head;

        if (head && head->next)
        {
            ResultHead = head->next;
        }

        recurSwap(head);

        return ResultHead;
    }
};
