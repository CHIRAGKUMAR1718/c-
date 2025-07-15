class Solution {
  public:
    bool f(Node* curr1,Node* curr2,bool start){
        if(curr1==NULL || curr2==NULL || curr2->next==NULL) return false;
        if(curr1==curr2 && start) return true;
        return f(curr1->next,curr2->next->next,true);
    }
    bool detectLoop(Node* head) {
        Node* curr1=head;
        Node* curr2=head;
        return f(curr1,curr2,false);
    }
};