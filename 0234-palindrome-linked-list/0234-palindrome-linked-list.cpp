/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    bool isPalindrome(ListNode* head) {
        deque<ListNode*> Q;

        while (head != nullptr)
        {
            Q.push_back(head);
            head = head->next;
        }

        while (Q.size() > 1)
        {
            if (Q.front()->val == Q.back()->val)
            {
                Q.pop_front();
                Q.pop_back();
            }
            else
            {
                break;
            }
        }
    
        return Q.size() <= 1;
    }
};
