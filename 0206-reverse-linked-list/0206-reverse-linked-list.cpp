
class Solution
{
public:
    ListNode* reverse(ListNode* cur, ListNode* prev)
    {
        if (nullptr == cur)
            return prev;

        ListNode* NextNode = cur->next;
        cur->next = prev;

        return reverse(NextNode, cur);
    }

    ListNode* reverseList(ListNode* head)
    { 
        return reverse(head, nullptr);
    }
};
