struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode Dummy;
        ListNode* cur = &Dummy;
        int cnt = 0;
        while(l1 != nullptr && l2 != nullptr){
            ListNode* tmp = new ListNode();
            int _ = cnt + l1->val + l2->val;
            if(_ >= 10){
                tmp->val = _ % 10;
                cnt = _ / 10;
            }else{
                tmp->val = _;
                cnt = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            cur->next = tmp;
            cur = cur->next;
        }
        while(l1 != nullptr){
            int _ = cnt + l1->val;
            ListNode* tmp = new ListNode();
            tmp->val = _ % 10;
            cnt = _ / 10;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int _ = cnt + l2->val;
            ListNode* tmp = new ListNode();
            tmp->val = _ % 10;
            cnt = _ / 10;
            cur->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }
        if(cnt){
            ListNode* tmp = new ListNode();
            tmp->val = cnt;
            cur->next = tmp;
        }
        return Dummy.next;
    }
};
