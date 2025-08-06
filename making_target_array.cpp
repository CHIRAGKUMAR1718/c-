class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans=0;
        int n=nums.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            v[i]=target[i]-nums[i];
            cout<<v[i]<<"   ";
        }
        int prev=0;
        for(int i=0;i<n;i++){
            if(prev>=0 && v[i]<0) ans+=abs(v[i]);
            else if(prev<0 && v[i]>0) ans+=abs(v[i]);
            else if(abs(v[i])>abs(prev)) ans+=abs(v[i])-abs(prev);
            prev=v[i];
        }
        return ans;
    }
};