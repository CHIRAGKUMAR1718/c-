class Solution {
public:
    void f(int& p1,int& p2,int idx,vector<int>&nums,bool flag){
        if(idx>=nums.size()) return;
        if(nums[idx]%2!=0) flag=!flag;
        if(((idx+1)%6)==0) flag=!flag;
        if(flag) p1+=nums[idx];
        else p2+=nums[idx];
        f(p1,p2,idx+1,nums,flag);
    }
    int scoreDifference(vector<int>& nums) {
        int p1=0;
        int p2=0;
        int n=nums.size();
        int idx=0;
        f(p1,p2,idx,nums,true);
        return p1-p2;
    }
};