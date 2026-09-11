class MyLinkedList {
public:
    ListNode* head;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        if(index<0){
            return -1;
        }
        if(head==NULL){
            return -1;
        }
        ListNode* temp=head;
        for(int i=0;i<index&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            return -1;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* newnode=new ListNode(val);
        newnode->next=head;
        head=newnode;
    }
    
    void addAtTail(int val) {
        ListNode*newnode=new ListNode(val);
        if(head==NULL){
            head=newnode;
            return;
        }
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newnode=new ListNode(val);
        if(index<0){
            return;
        }
        if(index==0){
            newnode->next=head;
            head=newnode;
            return;
        }
        ListNode* temp=head;
        for(int i=0;i<index-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            return;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||head==NULL){
            return;
        }
        if(index==0){
             ListNode* temp=head;
            head=head->next;
            delete temp;
            return;
        }
         ListNode* temp=head;
        for(int i=0;i<index-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL||temp->next==NULL){
            return;
        }
         ListNode* del=temp->next;
        temp->next=del->next;
        delete del;
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