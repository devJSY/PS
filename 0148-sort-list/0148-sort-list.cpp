struct comp
{
    bool operator()(ListNode* A, ListNode* B) { return A->val > B->val; }
};

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        while (head)
        {
            ListNode* Node = head;
            pq.push(Node);
            head = head->next;
            Node->next = nullptr;
        }

        ListNode Root;
        ListNode* Node = &Root;

        while (!pq.empty())
        {
            Node->next = pq.top();
            pq.pop();
            Node = Node->next;
        }

        return Root.next;
    }
};