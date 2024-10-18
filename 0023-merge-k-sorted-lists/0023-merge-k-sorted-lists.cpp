struct comp
{
    bool operator()(ListNode* A, ListNode* B) { return A->val > B->val; }
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, comp> pQ;

        for (int i = 0; i < lists.size(); ++i)
        {
            ListNode* Node = lists[i];
            while (Node)
            {
                pQ.push(Node);
                ListNode* NextNode = Node->next;
                Node->next = nullptr;
                Node = NextNode;
            }
        }

        ListNode* root = nullptr;
        ListNode* head = nullptr;

        while (!pQ.empty())
        {
            if (!root)
            {
                root = pQ.top();
            }

            if (!head)
            {
                head = pQ.top();
            }
            else
            {
                head->next = pQ.top();
                head = head->next;
            }

            pQ.pop();
        }

        return root;
    }
};
