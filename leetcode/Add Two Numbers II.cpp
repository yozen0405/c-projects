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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr&&l2==nullptr) return l1;
        stack<int> stk1;
        stack<int> stk2;
        while(l1!=nullptr){
            stk1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            stk2.push(l2->val);
            l2=l2->next;
        }
        int num=0,cur=0;
        ListNode* head=new ListNode(0);
        stack<int> stk3;
        do{
            cur=num;
            if(stk1.size()&&stk2.size()){
                cur=num+stk1.top()+stk2.top();
                stk1.pop();
                stk2.pop();
            }
            else{
                if(stk1.size()){
                    cur+=stk1.top();
                    stk1.pop();
                }
                if(stk2.size()){
                    cur+=stk2.top();
                    stk2.pop();
                }
            }
            stk3.push(cur%10);
            num=cur/10;
        }while(!(stk1.empty()&&stk2.empty()&&num==0));
        bool first=true;
        ListNode* ret=head;
        while(!stk3.empty()){
            if(first){
                head->val=stk3.top();
                stk3.pop();
                first=false;
            } 
            else{
                ListNode* nx=new ListNode(stk3.top());
                head->next=nx;
                head=nx;
                stk3.pop();
            }
        }
        return ret;
        
    }
};
