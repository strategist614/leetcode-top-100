#include <cstddef>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> mp;
        while(head != nullptr){
            if(mp.find(head) == mp.end()) {
                mp[head] = 1;
                head = head->next;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
