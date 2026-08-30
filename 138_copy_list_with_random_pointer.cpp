#include <cstddef>
#include <map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        int pos = 0;
        vector<Node*> v;
        Node* hhead = head;
        map<Node*, int> mp;
        map<int, Node*> mp1;

        // 原节点 -> 下标
        while(head != nullptr){
            mp[head] = pos;
            head = head->next;
            pos++;
        }

        // 创建所有新节点
        head = hhead;
        while(head != nullptr){
            Node* node = new Node(head->val);
            v.push_back(node);
            head = head->next;
        }

        // 连接新链表 next
        Node* Dummy = new Node(0);
        Dummy->next = v[0];
        for(int i = 0; i < v.size() - 1; i++){
            v[i]->next = v[i + 1];
        }

        // 下标 -> 新节点
        Node* curr = Dummy->next;
        pos = 0;
        while(curr != nullptr){
            mp1[pos] = curr;
            curr = curr->next;
            pos++;
        }

        // 设置 random
        curr = Dummy->next;
        head = hhead;
        while(head != nullptr){
            if(head->random == nullptr){
                curr->random = nullptr;
            }else{
                int p = mp[head->random];
                curr->random = mp1[p];
            }

            curr = curr->next;
            head = head->next;
        }

        return Dummy->next;
    }
};
