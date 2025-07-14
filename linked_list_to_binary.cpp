class Solution {
public:
    void f(ListNode* head,int& ans,int& p){
        if(head==NULL) return;
        f(head->next,ans,p);
        ans+=head->val*p;
        p*=2;
    }
    int getDecimalValue(ListNode* head) {
        int ans=0;
        int p=1;
        f(head,ans,p);
        return ans;
    }
};