/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;
        ListNode* cur=head;
        while(!mp[cur]){
            if(cur==nullptr) return false;
            mp[cur]++;
            cur=cur->next;
        }
        return true;
    }
};
