class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode root;
        ListNode* Node = &root;

        int quotient = 0;
        while (l1 && l2)
        {
            int sum = quotient + l1->val + l2->val;

            Node->next = new ListNode;
            Node = Node->next;
            Node->val = sum % 10;

            quotient = sum / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int sum = quotient + l1->val;

            Node->next = new ListNode;
            Node = Node->next;
            Node->val = sum % 10;

            quotient = sum / 10;
            l1 = l1->next;
        }

        while (l2)
        {
            int sum = quotient + l2->val;

            Node->next = new ListNode;
            Node = Node->next;
            Node->val = sum % 10;

            quotient = sum / 10;
            l2 = l2->next;
        }

        if (quotient)
        {
            Node->next = new ListNode;
            Node = Node->next;
            Node->val = quotient;
        }

        return root.next;
    }
};
