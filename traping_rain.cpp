class Solution {
public:
    int n;
    vector<int> st;
    void built(int lo,int hi,int i,vector<int>&height){
        int mid=lo+(hi-lo)/2;
        if(lo==hi){
            st[i]=height[lo];
            return;
        }
        built(lo,mid,2*i+1,height);
        built(mid+1,hi,2*i+2,height);
        st[i]=max(st[2*i+1],st[2*i+2]);
    }
    int get(int l,int h,int lo,int hi,int i){
        if(lo>h || hi<l) return INT_MIN;
        if(lo>=l && hi<=h) return st[i];
        int mid=lo+(hi-lo)/2;
        int a=get(l,h,lo,mid,2*i+1);
        int b=get(l,h,mid+1,hi,2*i+2);
        return max(a,b);
    }
    int trap(vector<int>& height) {
        n=height.size();
        st.resize(4*n);
        built(0,n-1,0,height);
        int ans=0;
        for(int i=1;i<n-1;i++){
            int l1=0;
            int h1=i-1;
            int l2=i+1;
            int h2=n-1;
            int a=get(l1,h1,0,n-1,0);
            int b=get(l2,h2,0,n-1,0);
            ans+=max(min(a,b)-height[i],0);
        }
        return ans;
    }
};