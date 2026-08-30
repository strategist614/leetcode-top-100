struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* Dummy = new ListNode();
        Dummy->next = head;
        ListNode* cur = new ListNode();
        ListNode* pre = new ListNode();
        cur = head;
        pre = Dummy;
        while(cur != nullptr && cur->next != nullptr){
            ListNode* _ = cur->next->next;
            ListNode* __ = cur->next;
            pre->next = __;
            __->next = cur;
            cur->next = _;
            pre = cur;
            cur = _;
        }
        return Dummy->next;
    }
};
