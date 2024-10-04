class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode* RootNode = head;
        ListNode* LastNode = head;

        int cnt = 1;

        while (LastNode && LastNode->next)
        {
            LastNode = LastNode->next;
            ++cnt;
        }

        // 갯수가 2개 이하인 리스트는 변환할 필요가 없으므로 예외처리
        if (cnt <= 2)
            return head;

        cnt /= 2;
        ListNode* tailNode = LastNode;

        while (cnt && head && head->next)
        {
            ListNode* EvenNode = head->next;

            // 홀수 끼리 연결
            head->next = head->next->next;

            // 현재 짝수노드를 맨뒤로 연결
            tailNode->next = EvenNode;
            tailNode = EvenNode;
            tailNode->next = nullptr;

            head = head->next;
            --cnt;
        }

        return RootNode;
    }
};
