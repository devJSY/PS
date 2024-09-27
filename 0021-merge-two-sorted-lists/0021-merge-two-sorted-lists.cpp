class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* result = nullptr;
        ListNode* head = nullptr;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                if (result)
                    result->next = list1;
                else
                    head = list1;

                result = list1;

                list1 = list1->next;
            }
            else
            {
                if (result)
                    result->next = list2;
                else
                    head = list2;

                result = list2;

                list2 = list2->next;
            }
        }

        while (list1)
        {
            if (result)
                result->next = list1;
            else
                head = list1;

            result = list1;
            list1 = list1->next;
        }

        while (list2)
        {
            if (result)
                result->next = list2;
            else
                head = list2;

            result = list2;
            list2 = list2->next;
        }

        return head;
    }
};
