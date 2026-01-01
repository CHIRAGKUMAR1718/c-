class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int nsi[n];
        stack<int> st;
        nsi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        int psi[n];
        stack<int> pt;
        psi[0]=-1;
        pt.push(0);
        for(int i=1;i<n;i++){
            while(pt.size()>0 && arr[pt.top()]>=arr[i]){
                pt.pop();
            }
            if(pt.size()==0) psi[i]=-1;
            else psi[i]=pt.top();
            pt.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            int area=arr[i]*(nsi[i]-psi[i]-1);
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};