
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* cur=head;
        int num=-1000;
        ListNode* nx;
        while(cur!=nullptr){
            num=cur->val;
            nx=cur->next;
            while(nx!=nullptr&&nx->val==num){
                nx=nx->next;
            }
            cur->next=nx;
            cur=nx;
        }
        return head;
    }
};
