struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Dummy = new ListNode();
        Dummy->next = head;
        int size = 0;
        while(head != nullptr){
            size ++;
            head = head->next;
        }
        int cnt = size - n + 1;
        ListNode* cur = Dummy;
        int pos = 0;
        while(cur != nullptr){
            if(pos + 1 == cnt){
                cur->next = cur->next->next;
                break;
            }
            pos++;
            cur = cur->next;
        }
        return Dummy->next;
    }
};
