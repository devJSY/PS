class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        deque<ListNode*> Q;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                Q.push_back(list1);
                list1 = list1->next;
            }
            else
            {
                Q.push_back(list2);
                list2 = list2->next;
            }
        }

        while (list1)
        {
            Q.push_back(list1);
            list1 = list1->next;
        }

        while (list2)
        {
            Q.push_back(list2);
            list2 = list2->next;
        }

        ListNode* head = nullptr;
        if (!Q.empty())
            head = Q.front();

        while (!Q.empty())
        {
            ListNode* front = Q.front();
            Q.pop_front();

            if (!Q.empty())
            {
                front->next = Q.front();
            }
        }

        return head;
    }
};
