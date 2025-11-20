class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int pre=-1;
        int curr=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(curr<nums[i][0]){
                ans+=2;
                curr=nums[i][1];
                pre=curr-1;
            }
            else if(curr>=nums[i][0] && pre<nums[i][0]){
                pre=curr;
                curr=nums[i][1];
                if(pre==curr) pre-=1;
                ans+=1;
            }
        }
        return ans;
    }
};