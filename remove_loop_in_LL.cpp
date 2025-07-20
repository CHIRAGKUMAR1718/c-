class Solution {
  public:
    
    bool f(Node* slow,Node* fast){
        if(fast==NULL || fast->next==NULL) return false;
        if(slow==fast) return true;
        return f(slow->next,fast->next->next);
    }
    
    void removeLoop(Node* head) {
        if(head==NULL || head->next==NULL) return;
        bool flag=f(head,head->next);
        if(flag){
            unordered_set<Node*> visited;
            Node* temp=head;
            visited.insert(temp);
            while(true){
                if(visited.count(temp->next)) break;
                temp=temp->next;
                visited.insert(temp);
            }
            temp->next=NULL;
        }
    }
};