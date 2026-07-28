class Solution {
public:
    int parent(int target){
        long long x=1;
        while(target>=x){
            x=(x<<1);
        }
        long long end=x-1;
        long long start=x>>1;
        int kd=end-target;
        return start+kd;
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while(label>1){
            ans.push_back(label);
            label=parent(label/2);
        }
        ans.push_back(1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};