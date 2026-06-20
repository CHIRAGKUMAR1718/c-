class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        unordered_map<int,int> m;
        m[0]=0;
        for(auto i:restrictions) m[i[0]]=i[1];
        vector<int> left(n);
        left[0]=0;
        for(int i=1;i<n;i++){
            if(m.count(i)){
                left[i]=min(m[i],left[i-1]+diff[i-1]);
            }else left[i]=left[i-1]+diff[i-1];
        }
        vector<int> right(n);
        right[n-1]=left[n-1];
        for(int i=n-2;i>=0;i--){
            if(m.count(i)){
                right[i]=min(m[i],right[i+1]+diff[i]);
            }else right[i]=right[i+1]+diff[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=min(left[i],right[i]);
        }
        int original_ans=0;
        for(auto i:ans) original_ans=max(original_ans,i);
        return original_ans;
    }
};