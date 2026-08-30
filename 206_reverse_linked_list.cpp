struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* curr = head;
        ListNode* nt = curr->next;
        curr->next = nullptr;
        while(nt != nullptr){
            ListNode* ntt = nt->next;
            nt->next = curr;
            curr = nt;
            nt = ntt;
        }
        return curr;
    }
};
