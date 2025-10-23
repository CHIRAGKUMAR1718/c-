class Solution {
public:
    ListNode* ans=new ListNode(-1);
    void ff(ListNode* head){
        if(head==NULL) return;
        ListNode* prev=head;
        ListNode* curr=head->next;
        if(curr){
            ListNode* f=new ListNode(curr->val);
            ListNode* s=new ListNode(prev->val);
            ans->next=f;
            ans=ans->next;
            ans->next=s;
            ans=ans->next;
            ff(head->next->next);
        }
        else{
            ListNode* s=new ListNode(prev->val);
            ans->next=s;
            ans=ans->next;
            return;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=ans;
        ff(head);
        return temp->next;
    }
};