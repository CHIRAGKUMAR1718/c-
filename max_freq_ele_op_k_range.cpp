class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        int n=nums.size();
        int max_ele=INT_MIN;
        for(auto i:nums) max_ele=max(max_ele,i);
        max_ele+=k;
        map<int,int> target;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            int l=max(nums[i]-k,0);
            int r=min(nums[i]+k,max_ele);
            target[l]++;
            target[r+1]--;
            target[nums[i]]+=0;
        }
        int result=1;
        int cum_sum=0;
        for(auto it=target.begin();it!=target.end();it++){
            int ele=it->first;
            it->second+=cum_sum;
            int pre=freq[ele];
            int ao=it->second-pre;
            int changes=min(ao,op);
            result=max(result,pre+changes);
            cum_sum=it->second;
        }
        return result;
    }
};