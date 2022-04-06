class MyLinkedList {
public:
    int size=0;
    ListNode* head= new ListNode();
    ListNode* tail= new ListNode(0);
    MyLinkedList() {
        size=0;
    }
    
    int get(int index) {
        if(index>=size||index<0) return -1;
        ListNode* tmp=new ListNode();
        tmp=head;
        for(int i=0;i<size;i++){
            if(index==i){
                return tmp->val;
            }
            if(i!=size-1) tmp=tmp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
       ListNode* tmp=new ListNode(val);
        if(size>=1){
            tmp->next=head;
            head=tmp;
        } 
        else{
            head=tmp;
            tail=tmp;
        }
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* tmp=new ListNode(val);
        if(size>=1){
            tail->next=tmp;
            tail=tmp;
        } 
        else{
            head=tmp;
            tail=tmp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size||index<0) return;
        ListNode* tmp=new ListNode(val);
        if(index==0){
            if(size>=1){
                tmp->next=head;
                head=tmp;
            } 
            else{
                head=tmp;
                tail=tmp;
            }
            size++;
            return;
        }
        if(index==size){
            if(size>=1){
                tail->next=tmp;
                tail=tmp;
            } 
            else{
                head=tmp;
                tail=tmp;
            }
            size++;
            return;
        }
        tmp=head;
        ListNode* tmp2=new ListNode(val);
        for(int i=0;i<size+1;i++){
            if(index-1==i){
                tmp2->next=tmp->next;
                tmp->next=tmp2;
            }
            if(i!=size) tmp=tmp->next;
            else tail=tmp;
        }
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index>=size||index<0) return;
        ListNode* tmp=new ListNode();
        if(index==0){
            if(size>=1){
                head=head->next;
            }
            size--;
            return;
        }
        tmp=head;
        ListNode* nx=tmp->next;
        int i=0;
        while(tmp->next!=nullptr){
            nx=tmp->next;
            if(index-1==i){
                tmp->next=tmp->next->next;
            }
            if(tmp->next!=nullptr) tmp=nx;
            else tail=tmp;
            ++i;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
