class CustomStack {
public:
int n;
stack<int> st;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(st.size()!=n){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.size()==0) return -1;
        int a=st.top();
        st.pop();
        return a;
    }
    
    void increment(int k, int val) {
        stack<int> helper;
        while(st.size()!=0){
            helper.push(st.top());
            st.pop();
        }
        while(helper.size()!=0 && k--){
            int a=helper.top();
            a+=val;
            helper.pop();
            st.push(a);
        }
        while(helper.size()!=0){
            st.push(helper.top());
            helper.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */